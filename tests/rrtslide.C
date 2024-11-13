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


#include "rrtslide.h"


// *********************************************************************
// *********************************************************************
// CLASS:     RRTSlide
//
// *********************************************************************
// *********************************************************************


RRTSlide::RRTSlide(Problem *p):RRTCon(p) {
  int i;
  
  NumNodes = 100;  // Each node is costly
  RandomTrials = 50;
  // Initialize the random directions
  NumDirections = 1000;
  RandomDirections = vector<MSLVector>(NumDirections);
  for (i = 0; i < NumDirections; i++) {
    RandomDirections[i] = RandomDirection();
  }
}


MSLVector RRTSlide::SelectInput(const MSLVector &x1, const MSLVector &x2, 
				MSLVector &nx_best, bool &success,
				bool forward = true)
{
  MSLVector u_best,nx,tu;
  list<MSLVector>::iterator u;
  double d,d_min;
  success = false;
  int i;
  d_min = (forward) ? P->Metric(x1,x2) : P->Metric(x2,x1);
  list<MSLVector> il = P->GetInputs(x1);

  if (Holonomic) { // Just do interpolation

    // First try the best direction
    u_best = P->InterpolateState(x1,x2,0.1) - x1;
    u_best = u_best.norm(); // Normalize the direction
    nx_best = P->Integrate(x1,u_best,PlannerDeltaT);
    SatisfiedCount++;
    if (P->Satisfied(nx_best)) {
      //if (forward)
      //	cout << "H" << flush;
      success = true;
      return u_best;
    }

    // Now try some random inputs
    for (i = 0; i < RandomTrials; i++) {
      tu = RandomDirections[i];
      nx = P->Integrate(x1,tu,PlannerDeltaT);
      d = P->Metric(nx,x2);
      SatisfiedCount++;
      if ((d < d_min)&&(x1 != nx)) { 
	if (P->Satisfied(nx)) {
	  d_min = d; u_best = tu; nx_best = nx; success = true;
	  if (forward) {
	    //cout << "R"; 
	    //cout << "  i: " << i << "  d: " << 
	    //  P->DistanceComp(P->StateToConfiguration(nx)) << "\n";
	  }
	  return u_best;
	}
      }      
    }
  }
  else {
  
    // This will be called whenever the best input fails for holonomic case!
    // Nonholonomic (the more general case -- look at Inputs)
    forall(u,il) {
      if (forward)
	nx = P->Integrate(x1,*u,PlannerDeltaT);
      else
	nx = P->Integrate(x1,*u,-PlannerDeltaT);
      
      d  = (forward) ? P->Metric(nx,x2): P->Metric(x2,nx);
      
      SatisfiedCount++;
      
      if ((d < d_min)&&(x1 != nx)) { 
	if (P->Satisfied(nx)) {
	  d_min = d; u_best = *u; nx_best = nx; success = true;
	}
      }
    }
  }

  //cout << "u_best: " << u_best << "\n";
  if (forward) {
    if (!success)
      cout << "  F";
  }

  return u_best;
}



bool RRTSlide::Connect(const MSLVector &x, 
		       MSLTree *t,
		       MSLNode *&nn, bool forward = true) {
  MSLNode *nn_prev,*n_best;
  MSLVector nx,nx_prev,u_best;
  bool success;
  double d,d_prev,clock,tstep;
  int steps;

  tstep = PlannerDeltaT;
  if ((!Holonomic)&&(!forward))
    tstep *= -1.0;

  n_best = SelectNode(x,t,forward);

  if (forward) 
    cout <<
      "CONNECT  d: " << 
      P->DistanceComp(P->StateToConfiguration(n_best->State())); 
  //	 << "\n";

  u_best = SelectInput(n_best->State(),x,nx,success,forward); 
  steps = 0;
           // nx gets next state
  if (success) {   // If a collision-free input was found
    d = P->Metric(nx,x); d_prev = d;
    nx_prev = nx; // Initialize
    nn = n_best;
    clock = PlannerDeltaT;
    while ((P->Satisfied(nx))&&
	   (clock <= ConnectTimeLimit)&&
	   (d <= d_prev))
      {
        SatisfiedCount++;
	steps++; // Number of steps made in connecting
	nx_prev = nx;
	d_prev = d; nn_prev = nn;

	// First try the previous input
	nx = P->Integrate(nx_prev,u_best,tstep);
	d = P->Metric(nx,x);

	// If failure, then try a new input
	if (!(P->Satisfied(nx))||(d > d_prev)) { 
	  u_best = SelectInput(nx_prev,x,nx,success,forward);
	  d = P->Metric(nx,x);
	}

	clock += PlannerDeltaT;

      }

    nn = t->Extend(n_best, nx, u_best, PlannerDeltaT);
  }

  cout << " Steps: " << steps << "\n";
  return success;
}



// Generate a MSLVector in a random direction with unit magnitude
MSLVector RRTSlide::RandomDirection()
{
  MSLVector delta;
  int i,j,dim;
  double r,w;

  dim = P->StateDim;

  delta = MSLVector(dim);

  // Pick a random direction
  w = 0.0;
  for (i = 0; i < dim; i++) {
    // Generate sample from N(0,1)
    delta[i] = 0.0;
    for (j = 0; j < 12; j++) {
      R >> r; delta[i] += r;
    }
    delta[i] -= 6.0;
    w += delta[i]*delta[i];
  }
  w = sqrt(w);  
  for (i = 0; i < dim; i++) {
    delta[i] = delta[i]/w;
  }

  //cout << "delta: " << delta << "\n";
  return delta;
}
