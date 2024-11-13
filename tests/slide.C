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

#include <math.h>
#include <stdlib.h>

// This includes the core header files of the Motion Strategy Library
#include <MSL/MSL.h>
#include <MSL/rendergl.h>

// This includes the new model called Model3DRigidHelical
#include "rrtslide.h"


int main(int argc, char *argv[])
{
  string path;
  GuiPlanner *gui;
  Model *m = NULL;
  Geom *g = NULL;
  Problem *prob;

  if (argc < 2) {
    cout << "Try this:    slide ../data/cross\n";
    exit(-1);
  }

  path = string(argv[1])+"/";

  if (!is_directory(path)) {
    cout << "Error:   Directory does not exist\n";
    exit(-1);
  }

  SetupProblem(m,g,path);
  prob = new Problem(g,m,path);

  // Initialize everything: Gui, Scene, Render, and RRT
  // All of them will use the same file path
  gui = new GuiPlanner(new RenderGL(new Scene(prob, path), path),
		       new RRTSlide(prob));

  // Activate the GUI
  gui->Start();

  return 0;
}

