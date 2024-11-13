//----------------------------------------------------------------------
//               The Motion Strategy Library (MSL)
//----------------------------------------------------------------------
//
// Copyright (c) 1998-2000 Iowa State University and Steve LaValle.  
// All Rights Reserved.
// 
// Permission to use, copy, and distribute this software and its 
// documentation is hereby granted free of charge, provided that 
// (1) it is not a component of a commercial product, and 
// (2) this notice appears in all copies of the software and
//     related documentation. 
// 
// Iowa State University and the author make no representations
// about the suitability or fitness of this software for any purpose.  
// It is provided "as is" without express or implied warranty.
//----------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
#include <math.h>
using namespace std;

#include <list>
#include <vector>

#define PI 3.1415926535897932385


int main(int argc, char **argv)
{
  double xc, yc, zc, in_rad, out_rad;
  int is, os;

  if (argc < 8) {
    cout << "Usage: torus xc yc zv ir or is os\n";
    cout << "{x,y,z}c: center of the torus, {x,y,z}-coordinate\n";
    cout << "{i,o}r: {inner, outer} radius of the torus\n";
    cout << "{i,o}s: {inner, outer} number of sides of the torus\n";
    exit(1);
  }

  xc = atof(argv[1]);
  yc = atof(argv[2]);
  zc = atof(argv[3]);
  in_rad = atof(argv[4]);
  out_rad = atof(argv[5]);

  is = atoi(argv[6]);
  os = atoi(argv[7]);

  if ((is == 0) || (os == 0)) {
    cout << "Number of inner steps and outer steps may not be 0.\n";
    exit(1);
  }

  //  list<vector> pl;
  vector<double> p1,p2,p3;
  int i,j;
  double u,v;
  vector<double> x(3, 0.0);
  vector<double> torus[os][is];

  for (i = 0; i < os; i++) {
    u = i*2.0*PI/os;
    for (j = 0; j < is; j++) {
      v = j*2.0*PI/is;
      x[0] = xc + (out_rad + in_rad * cos(v))*cos(u);
      x[1] = yc + in_rad * sin(v);
      x[2] = zc + (out_rad + in_rad * cos(v))*sin(u);
      torus[i][j] = x;
    }
  }

  for (i = 0; i < os; i++) {
    for (j = 0; j < is; j++) {
      p1 = torus[i][j];
      p2 = torus[(i+1) % os][j];
      p3 = torus[i][(j+1) % is];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
      p1 = torus[i][(j+1) % is];
      p2 = torus[(i+1) % os][j];
      p3 = torus[(i+1) % os][(j+1) % is];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
    }
  }

}
