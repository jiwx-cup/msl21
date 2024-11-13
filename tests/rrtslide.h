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

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>

#include <MSL/vector.h>
#include <MSL/tree.h>
#include <MSL/rrt.h>
#include <MSL/defs.h>

//! In the Connect method, slide along the walls
class RRTSlide: public RRTCon {
 public:
  RRTSlide(Problem *p);
  virtual ~RRTSlide() {};

  int RandomTrials;
  int NumDirections;
  vector<MSLVector> RandomDirections;

  //! Select the input that gets closest to x2 from x1
  virtual MSLVector SelectInput(const MSLVector &x1, const MSLVector &x2, 
				MSLVector &nx_best, 
				bool &success, bool forward);

  //! Iterated Extend
  virtual bool Connect(const MSLVector &x, MSLTree *t, MSLNode *&nn,
		       bool forward);

  MSLVector RandomDirection();
};






