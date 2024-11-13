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

#include <list>
#include <vector>
#include <math.h>
using namespace std;

#define LATITUDESTEPS 30
#define LONGITUDESTEPS 25
#define PI 3.1415926535897932385


int main(int argc, char **argv)
{ 
  vector<double> p1,p2,p3;
  int i,j;
  double u,v;
  vector<double> x(3, 0.0);
  vector<double> sphere[LATITUDESTEPS][LONGITUDESTEPS];

  if (argc < 5) {
    cout << "Usage:    sphere xc yc zc r \n";
    exit(-1);
  }

  double xc = atof(argv[1]);
  double yc = atof(argv[2]);
  double zc = atof(argv[3]);
  double radius = atof(argv[4]);

  for (i = 0; i < LATITUDESTEPS; i++) {
    u = i*PI/(LATITUDESTEPS-1);
    for (j = 0; j < LONGITUDESTEPS; j++) {
      v = j*2.0*PI/LONGITUDESTEPS;
      x[0] = xc + radius*cos(v)*sin(u);
      x[1] = yc + radius*sin(v)*sin(u);
      x[2] = zc + radius*cos(u);
      sphere[i][j] = x;
    }
  }

  for (i = 0; i < LATITUDESTEPS; i++) {
    for (j = 0; j < LONGITUDESTEPS; j++) {
      p1 = sphere[i][j];
      p2 = sphere[(i+1) % LATITUDESTEPS][j];
      p3 = sphere[i][(j+1) % LONGITUDESTEPS];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
      p1 = sphere[i][(j+1) % LONGITUDESTEPS];
      p2 = sphere[(i+1) % LATITUDESTEPS][j];
      p3 = sphere[(i+1) % LATITUDESTEPS][(j+1) % LONGITUDESTEPS];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
    }
  }

}
  

