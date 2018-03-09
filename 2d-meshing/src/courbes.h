#ifndef COURBES_H
#define COURBES_H

#include <iostream>
#include <fstream>
void write_csv(const std::string & file_title,const std::list<double> x,const std::list<double> y )
{
      std::ofstream myfile;
      myfile.open (file_title);
      for(int i=0;i<x.size();i++)
      {
          myfile<<x[x.begin()+i];//<<","<<y[i]<<std::endl;
      }
      myfile.close();
}

#endif // COURBES_H
