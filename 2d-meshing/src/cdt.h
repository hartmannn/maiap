#ifndef TRIANGULATION_H
#define TRIANGULATION_H

#include <CGAL/basic.h>
#include <CGAL/intersections.h> 
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Constrained_triangulation_plus_2.h>

#include <stack>
#include <sstream>

template <class Kernel,
class Vbb>
class My_vertex_base : public Vbb
{
public:
	typedef Vbb Base;
	typedef typename Kernel::Point_2 Point;

	template < typename TDS2 >
	struct Rebind_TDS {
		typedef typename Base::template Rebind_TDS<TDS2>::Other Vb2;
		typedef My_vertex_base<Kernel,Vb2>                       Other;
	};

private:

public:
	My_vertex_base()
		: Base()
	{
	}
	My_vertex_base(const Point & p, void* f)
		: Base(p,f)
	{
	}
	My_vertex_base(const Point & p)
		: Base(p)
	{
	}

	~My_vertex_base()
	{
	}
};


//---------------CLASS MY_FACE_BASE---------------------
template <class Kernel,
class Fbb>
class My_face_base : public Fbb
{
public:
	typedef  Fbb Base;
	typedef typename Base::Vertex_handle Vertex_handle;
	typedef typename Base::Face_handle Face_handle;
	typedef typename std::pair<Face_handle, int> Edge;

public:

private:
	// additional member data
	int m_location; // inside / outside / undetermined

public:
	template < typename TDS2 >
	struct Rebind_TDS {
		typedef typename Base::template Rebind_TDS<TDS2>::Other Fb2;
		typedef My_face_base<Kernel,Fb2>                   Other;
	};

public:
	My_face_base()
		: Base()
	{
		m_location = 0;
	}
	My_face_base(Vertex_handle v1,
		Vertex_handle v2,
		Vertex_handle v3)
		: Base(v1,v2,v3)
	{
		m_location = 0;
	}
	My_face_base(Vertex_handle v1,
		Vertex_handle v2,
		Vertex_handle v3,
		Face_handle f1,
		Face_handle f2,
		Face_handle f3)
		: Base(v1,v2,v3,f1,f2,f3)
	{
		m_location = 0;
	}
	My_face_base(Face_handle f)
		: My_face_base(f)
	{
		m_location = f->location();
	}

	My_face_base(Face_handle f,
		Edge c)
		: My_face_base(f)
	{
		m_location = (f->location());
	}

	// inside/outside/undetermined
	const int location() const { return m_location; }
	int& location() { return m_location; }
};

template <class CDT>
class CCDT : public CDT
{
public:

	// typedefs for basic primitives
	typedef typename CDT::Geom_traits Kernel;
	typedef typename Kernel::FT FT;
	typedef typename Kernel::Point_2    Point;
	typedef typename Kernel::Ray_2      Ray;
	typedef typename Kernel::Segment_2  Segment;
	typedef typename Kernel::Triangle_2 Triangle;

	typedef CCDT<CDT> Cdt;
	// handles

	typedef typename Cdt::Face_handle         Face_handle;
	typedef typename Cdt::Vertex_handle       Vertex_handle;

	// iterators
	typedef typename Cdt::Face_iterator       Face_iterator;
	typedef typename Cdt::Edge_iterator       Edge_iterator;
	typedef typename Cdt::Vertex_iterator     Vertex_iterator;

	// circulators
	typedef typename Cdt::Edge_circulator     Edge_circulator;
	typedef typename Cdt::Edge Edge;

private:

public:
	CCDT() 
	{
	}
	virtual ~CCDT() 
	{
	}

	enum {INSIDE = -1,
		UNDETERMINED = 0,
		OUTSIDE = 1};

public:

	// OPENGL DRAWINGS

	void gl_draw_unconstrained_edges(const unsigned char r,
		const unsigned char g,
		const unsigned char b)
	{
		::glLineWidth(1.0f);
		::glColor3ub(r,g,b);

		::glBegin(GL_LINES);
		typename CDT::Finite_edges_iterator e;
		for(e  = CDT::finite_edges_begin(); 
			e != CDT::finite_edges_end(); 
			e++) 
		{
			Edge edge = *e; // STL pair (see doc)
			if(this->is_constrained(edge))
				continue;
			Point p1 = edge.first->vertex(this->ccw(edge.second))->point();
			Point p2 = edge.first->vertex(this->cw(edge.second))->point();
			::glVertex2d(p1.x(),p1.y());
			::glVertex2d(p2.x(),p2.y());
		}
		::glEnd();
	}

	void gl_draw_constrained_edges(const unsigned char r,
		const unsigned char g,
		const unsigned char b)
	{
		::glLineWidth(3.0f);
		::glColor3ub(r,g,b);

		::glBegin(GL_LINES);
		typename CDT::Finite_edges_iterator e;
		for(e  = CDT::finite_edges_begin(); 
			e != CDT::finite_edges_end(); 
			e++) 
		{
			Edge edge = *e; // STL pair (see doc)
			if(!this->is_constrained(edge))
				continue;
			const Point& p1 = edge.first->vertex(this->ccw(edge.second))->point();
			const Point& p2 = edge.first->vertex(this->cw(edge.second))->point();
			::glVertex2d(p1.x(),p1.y());
			::glVertex2d(p2.x(),p2.y());
		}
		::glEnd();
	}

	void tag_faces_location(const int location)
	{
		for(typename CDT::All_faces_iterator f = CDT::all_faces_begin();
			f != CDT::all_faces_end();
			f++)
			f->location() = location;
	}

	bool insert_inside(const Point& p)
	{
		if (!is_inside(p))
			return false;

		CDT::insert(p);
		return true;
	}

	void tag_faces_inside_outside()
	{
		// reset all tags undetermined
		tag_faces_location(UNDETERMINED);

		// pick one seed face incident to the infinite vertex (virtual, connected
		// to all points on the convex hull. see CGAL documentation on triangulations)
		Face_handle seed = CDT::infinite_vertex()->face();
		seed->location() = OUTSIDE;
		std::stack<Face_handle> faces;
		faces.push(seed);

		while(!faces.empty())
		{
			Face_handle f = faces.top();
			faces.pop();
			const int& location = f->location();
			assert(location == OUTSIDE || location == INSIDE);
			for(unsigned int i=0;i<3;i++)
			{
				if(f->neighbor(i) != NULL)
					if(f->neighbor(i)->location() == UNDETERMINED)
					{
						// swap inside / outside if crosses a tagged facet
						bool constrained = f->is_constrained(i);
						f->neighbor(i)->location() = constrained ? -location : location;
						faces.push(f->neighbor(i));
					}
			}
		}
	}

	// draw inside face
	void gl_draw_inside_faces(unsigned char r,
		unsigned char g,
		unsigned char b)
	{
		::glColor3ub(r,g,b);
		::glBegin(GL_TRIANGLES);
		for(typename CDT::Finite_faces_iterator f = CDT::finite_faces_begin();
			f != CDT::finite_faces_end();
			f++)
		{
			if(f->location() == INSIDE)
			{
				const Point& p1 = f->vertex(0)->point();
				const Point& p2 = f->vertex(1)->point();
				const Point& p3 = f->vertex(2)->point();
				::glVertex2d(p1.x(),p1.y());
				::glVertex2d(p2.x(),p2.y());
				::glVertex2d(p3.x(),p3.y());
			}
		}
		::glEnd();
	}

	// utility function to know if a point is in the "inside" area
	bool is_inside(const Point& query)
	{
		if (CDT::dimension() < 2)
			return false;

        Face_handle f = CDT::locate(query);
		return f->location() == INSIDE;
	}

	// make simple box 
	void add_box()
	{
		Point a(0.0,0.0);
		Point b(1.0,0.0);
		Point c(1.0,1.0);
		Point d(0.0,1.0);
		this->insert_constraint(a,b);
		this->insert_constraint(b,c);
		this->insert_constraint(c,d);
		this->insert_constraint(d,a);
	}

	void add_circle()
	{
		Point center(0.5,0.5);
		const unsigned int nb_points = 100;
		const double incr = 360.0 / double(nb_points);
		std::vector<Vertex_handle> vertices;
		for (double angle = 0.0; angle < 360.0; angle += incr)
		{
			double angle_rad = (angle / 360.0) * 6.2831853;
			double x = center.x() + 0.5 * cos(angle_rad);
			double y = center.y() + 0.5 * sin(angle_rad);

			Vertex_handle v = this->insert(Point(x,y));
			vertices.push_back(v);
		}

		for(int i=0;i<nb_points;i++)
			this->insert_constraint(vertices[i],vertices[(i+1)%nb_points]);
	}

	// read PSLG (edg format)
	bool read_pslg(const char *pFilename)
	{
		std::ifstream in(pFilename);

		char line[512];
		in.getline(line, 512); // # edges (unused)

		while (in.getline(line, 512))
		{
			double x1, y1, x2, y2;
			std::stringstream string(line);
			string >> x1 >> y1 >> x2 >> y2; 
			Point a(x1, y1);
			Point b(x2, y2);
			this->insert_constraint(a,b);
		}
		return true;
	}

};

#endif // TRIANGULATION_H




