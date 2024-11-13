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

int main(int argc, char **argv)
{ 
  if (argc < 7) {
    cout << "Usage:    rectangle x1 y1 z1 x2 y2 z2 \n";
    exit(-1);
  }
 
  double x0=atof(argv[1]);
  double y0=atof(argv[2]);
  double z0=atof(argv[3]);
  double x1=atof(argv[4]);
  double y1=atof(argv[5]);
  double z1=atof(argv[6]);
  
  cout << "(" << x0 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z0 << ") ";
  cout << '\n';
  cout << "(" << x1 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z1 << ") ";
  cout << '\n';

  cout << "(" << x1 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z0 << ") ";
  cout << '\n';
  cout << "(" << x0 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z0 << ") ";
  cout << '\n';

  cout << "(" << x0 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z1 << ") ";
  cout << '\n';
  cout << "(" << x0 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z0 << ") ";
  cout << '\n';

  cout << "(" << x1 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z1 << ") ";
  cout << '\n';
  cout << "(" << x1 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z0 << ") ";
  cout << '\n';

  cout << "(" << x0 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x1 << "," << y0 << "," << z1 << ") ";
  cout << '\n';
  cout << "(" << x1 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y0 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z1 << ") ";
  cout << '\n';

  cout << "(" << x1 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z1 << ") ";
  cout << '\n';
  cout << "(" << x0 << "," << y1 << "," << z1 << ") ";
  cout << "(" << x0 << "," << y1 << "," << z0 << ") ";
  cout << "(" << x1 << "," << y1 << "," << z0 << ") ";
  cout << '\n';


}
  

