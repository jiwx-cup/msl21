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
using namespace std;

#include <list>
#include <vector>
#include <math.h>

#define LENGTHSTEPS 50
#define CIRCLESTEPS 20
#define PI 3.1415926535897932385


int main(int argc, char **argv)
{ 
  vector<double> p1,p2,p3;
  int i,j;
  double u,v;
  vector<double> x(3, 0.0);
  vector<double> cylinder[LENGTHSTEPS][CIRCLESTEPS];

  if (argc < 6) {
    cout << "Usage:    cylinder xp yp zp rad len\n";
    exit(-1);
  }

  double xp = atof(argv[1]);
  double yp = atof(argv[2]);
  double zp = atof(argv[3]);
  double radius = atof(argv[4]);
  double length = atof(argv[5]);

  for (i = 0; i < LENGTHSTEPS; i++) {
    u = i*length/LENGTHSTEPS;
    for (j = 0; j < CIRCLESTEPS; j++) {
      v = j*2.0*PI/CIRCLESTEPS;
      x[0] = xp + radius*cos(v);
      x[1] = yp + u;
      x[2] = zp + radius*sin(v);
      cylinder[i][j] = x;
    }
  }

  for (i = 0; i < LENGTHSTEPS; i++) {
    for (j = 0; j < CIRCLESTEPS; j++) {
      p1 = cylinder[i][j];
      p2 = cylinder[(i+1) % LENGTHSTEPS][j];
      p3 = cylinder[i][(j+1) % CIRCLESTEPS];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
      p1 = cylinder[i][(j+1) % CIRCLESTEPS];
      p2 = cylinder[(i+1) % LENGTHSTEPS][j];
      p3 = cylinder[(i+1) % LENGTHSTEPS][(j+1) % CIRCLESTEPS];
      cout << "(" << p1[0] << "," << p1[1] << "," << p1[2] << ") ";
      cout << "(" << p2[0] << "," << p2[1] << "," << p2[2] << ") ";
      cout << "(" << p3[0] << "," << p3[1] << "," << p3[2] << ")\n";
    }
  }

}
  

/*
cylinder.C: In function `int main(int, char **)':
cylinder.C:33: `leda_list' undeclared (first use this function)
cylinder.C:33: (Each undeclared identifier is reported only once
cylinder.C:33: for each function it appears in.)
cylinder.C:33: `leda_vector' undeclared (first use this function)
cylinder.C:33: `pl' undeclared (first use this function)
cylinder.C:34: parse error before `,'
cylinder.C:37: parse error before `('
cylinder.C:38: confused by earlier errors, bailing out

 */
