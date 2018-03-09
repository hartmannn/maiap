#ifndef _SCENE_H_
#define _SCENE_H_

// std
#include <fstream>
#include <algorithm>

// Qt
#include <QtOpenGL>

// CGAL
#include <CGAL/Exact_predicates_exact_constructions_kernel.h>
#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Constrained_Delaunay_triangulation_2.h>
#include <CGAL/Constrained_triangulation_plus_2.h>
#include <CGAL/Delaunay_mesh_face_base_2.h>

#include <CGAL/Triangulation_conformer_2.h>
#include <CGAL/Delaunay_mesher_2.h>
#include <CGAL/Delaunay_mesh_size_criteria_2.h>

#include "cdt.h"

#undef min
#undef max

// Courbes
#include "courbes.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

class Scene
{
public:
	typedef Kernel::FT FT;
	typedef Kernel::Point_2 Point;

	typedef CGAL::Triangulation_vertex_base_2<Kernel> Vb;
	typedef CGAL::Delaunay_mesh_face_base_2<Kernel> Fb;
	typedef My_vertex_base<Kernel,Vb> MVb;
	typedef My_face_base<Kernel,Fb> MFb;
	typedef CGAL::Triangulation_data_structure_2<MVb,MFb> MTDS;
	typedef CGAL::Exact_intersections_tag Itag;
	typedef CGAL::Constrained_Delaunay_triangulation_2<Kernel,MTDS,Itag> MCDT;
	typedef CGAL::Constrained_triangulation_plus_2<MCDT> MCDTP;
	typedef CCDT<MCDTP> CDT;

    typedef CGAL::Delaunay_mesh_size_criteria_2<CDT> Criteria; //ajout

private:
    // constrained Delaunay triangulation
	CDT m_cdt;

	Point m_mouse_pos;
    //Delaunay refinement
    double contrainte_taille;

public:    
	Scene()
	{
		m_cdt.add_box();
		m_cdt.tag_faces_inside_outside();
        contrainte_taille=100;
	}

	~Scene()
	{
		clear();
	}    

	void clear()
	{
		m_cdt.clear();
	}

	void add_vertex(const Point& p)
	{
		if(m_cdt.insert_inside(p))
			m_cdt.tag_faces_inside_outside();
	}

	void set_mouse_pos(const Point& pos) {  m_mouse_pos = pos; }

	void load(const QString& filename)
	{
		if (filename.contains(".edg", Qt::CaseInsensitive))
		{
			m_cdt.read_pslg(qPrintable(filename));
			m_cdt.tag_faces_inside_outside();
		}
	}

	void add_box()
	{
		m_cdt.add_box();
		m_cdt.tag_faces_inside_outside();
	}

	void add_circle()
	{
		m_cdt.add_circle();
		m_cdt.tag_faces_inside_outside();
	}

	void render()
	{
		m_cdt.gl_draw_inside_faces(200,200,255);
		m_cdt.gl_draw_unconstrained_edges(0,0,0);
		m_cdt.gl_draw_constrained_edges(200,0,0);
	}

	//-------------------------------------------------------
	// TO COMPLETE
	//-------------------------------------------------------

	void delaunay_conforming()
	{
        std::cout << "Delaunay conforming...";
        CGAL::make_conforming_Delaunay_2(m_cdt);
        std::cout << "done" << std::endl;
	}

	void gabriel_conforming()
	{
         std::cout << "Gabriel conforming...";
         CGAL::make_conforming_Gabriel_2(m_cdt);
         std::cout << "done" << std::endl;
	}

	// Delaunay refinement
	void refine()
	{
         std::cout << "Refine...";
         CGAL::refine_Delaunay_mesh_2(m_cdt,Criteria(0.125, 0.5));
         std::cout << "done" << std::endl;
	}

};

#endif // _SCENE_H_
