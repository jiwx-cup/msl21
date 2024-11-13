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

#include <fstream>
#include <math.h>

#include <MSL/model3d.h>

#include "modelnew.h"


// *********************************************************************
// *********************************************************************
// CLASS:     Model3DRigidHelical
//
// A nonlinear model that generates helical motions
// *********************************************************************
// *********************************************************************


// Constructor
Model3DRigidHelical::Model3DRigidHelical(string path = ""):Model3DRigid(path) {
  InputDim = 3;  // Override the default of 6 from Model3DRigid

  // Make inputs
  // u[0] is the speed: positive is forward, negative is reverse
  // u[1] is the steering: 0.0 is straight, 0.1 is left, -0.1 is right
  // u[2] changes altitude (Z direction)
  Inputs.clear();  // Clear whatever inputs came from Model3DRigid!!!
  Inputs.push_front(MSLVector(1.0,0.0,0.0));
  Inputs.push_front(MSLVector(1.0,0.1,0.0));
  Inputs.push_front(MSLVector(1.0,-0.1,0.0));
  Inputs.push_front(MSLVector(1.0,0.0,0.5));
  Inputs.push_front(MSLVector(1.0,0.1,0.5));
  Inputs.push_front(MSLVector(1.0,-0.1,0.5));
  Inputs.push_front(MSLVector(1.0,0.0,-0.5));
  Inputs.push_front(MSLVector(1.0,0.1,-0.5));
  Inputs.push_front(MSLVector(1.0,-0.1,-0.5));
  
  READ_OPTIONAL_PARAMETER(Inputs);

}


//! Give the equations of motion for a helical kinematic system
MSLVector Model3DRigidHelical::StateTransitionEquation(const MSLVector &x, 
						    const MSLVector &u) {

  MSLVector dx(6);
  
  // With respect to 0,1,5, it should look like a Reeds-Shepp car model

  dx[0] = u[0]*cos(x[5]);
  dx[1] = u[0]*sin(x[5]);
  dx[2] = u[2];  // Change elevation
  dx[3] = 0.0;   // No roll
  dx[4] = 0.0;   // No pitch
  dx[5] = u[0]*u[1];  // Some yaw

  return dx;
}


MSLVector Model3DRigidHelical::Integrate(const MSLVector &x, const MSLVector &u, 
				      const double &h)
{
  return RungeKuttaIntegrate(x,u,h);
}


