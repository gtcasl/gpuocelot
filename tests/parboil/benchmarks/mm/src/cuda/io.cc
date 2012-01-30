/***************************************************************************
 *cr
 *cr            (C) Copyright 2010 The Board of Trustees of the
 *cr                        University of Illinois
 *cr                         All Rights Reserved
 *cr
 ***************************************************************************/

/* I/O routines for reading and writing matrices in column-major
 * layout
 */

#include<fstream>
#include<iostream>
#include<vector>

bool readColMajorMatrixFile(const char *fn, int &nr_row, int &nr_col, std::vector<float>&v)
{
  std::cerr << "Opening file:"<< fn << std::endl;
  std::fstream f(fn, std::fstream::in);
  if ( !f.good() ) {
    return false;
  }

  // Read # of rows and cols
  f >> nr_row;
  f >> nr_col;

  float data;
  std::cerr << "Matrix dimension: "<<nr_row<<"x"<<nr_col<<std::endl;
  while (f.good() ) {
    f >> data;
    v.push_back(data);
  }
  v.pop_back(); // remove the duplicated last element

}

bool writeColMajorMatrixFile(const char *fn, int nr_row, int nr_col, std::vector<float>&v)
{
  std::cerr << "Opening file:"<< fn << " for write." << std::endl;
  std::fstream f(fn, std::fstream::out);
  if ( !f.good() ) {
    return false;
  }

  // Read # of rows and cols
  f << nr_row << " "<<nr_col<<" ";

  float data;
  std::cerr << "Matrix dimension: "<<nr_row<<"x"<<nr_col<<std::endl;
  for (int i = 0; i < v.size(); ++i) {
    f << v[i] << ' ';
  }
  f << "\n";
  return true;

}
