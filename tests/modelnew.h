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

#include <string.h>

#include "MSL/MSL.h"

//! A rigid robot that moves along helical paths in a 3D world
class Model3DRigidHelical: public Model3DRigid {
 public:
  Model3DRigidHelical(string path);
  virtual ~Model3DRigidHelical() {};
  virtual MSLVector StateTransitionEquation(const MSLVector &x, 
					    const MSLVector &u);
  virtual MSLVector Integrate(const MSLVector &x, const MSLVector &u, 
			      const double &h); 
};





