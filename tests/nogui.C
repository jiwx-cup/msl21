//----------------------------------------------------------------------
//               The Motion Strategy Library (MSL)
//----------------------------------------------------------------------
//
// Copyright (c) University of Illinois and Steven M. LaValle.     
// All Rights Reserved.
//
// Permission to use, copy, and distribute this software and its
// documentation is hereby granted free of charge, provided that
// (1) it is not a component of a commercial product, and
// (2) this notice appears in all copies of the software and
//     related documentation.
//
// The University of Illinois and the author make no representations
// about the suitability or fitness of this software for any purpose.  
// It is provided "as is" without express or implied warranty.
//----------------------------------------------------------------------


//! A simple test program that runs a planner without a GUI

#include <list>
#include <string>
#include <iostream>
#include <fstream>

#include <MSL/model3d.h>
#include <MSL/geomPQP.h>
#include <MSL/problem.h>
#include <MSL/rrt.h>

main(int argc, char **argv)
{ 
  string filepath("./data");

  Model *m = new Model3DRigid(filepath);
  Geom *g = new GeomPQP3DRigid(filepath);
  Problem *prob = new Problem(g,m,filepath);
  RRTConCon *rrt = new RRTConCon(prob);

  rrt->Holonomic = true;
  rrt->PlannerDeltaT = 0.5;
  rrt->NumNodes = 1000;

  if (rrt->Plan())
    cout << "Solution Path: \n" << rrt->Path << "\n";

}

