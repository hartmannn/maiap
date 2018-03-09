#include "courbes.h"

void write_csv(const std::string & file_title, const std::list<double> & x, const std::list<int> &y )
{
      std::ofstream myfile;
      myfile.open(file_title);// est-ce que ça écrase?

      std::list<double>::const_iterator x_it=x.begin();
      std::list<int>::const_iterator y_it=y.begin();

      myfile<<"angle min,nb de sommets"<<std::endl;

      for(int i=0;i<x.size();i++)
      {
          myfile<<*x_it<<","<<*y_it<<std::endl;
          x_it++;
          y_it++;
      }
      myfile.close();
}
