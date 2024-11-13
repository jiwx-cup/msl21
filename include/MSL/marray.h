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

#ifndef MSL_MARRAY_H
#define MSL_MARRAY_H

#include "vector.h"
#include "mslio.h"

//! A multidimensional array made from a 1D vector

template<class E> class MultiArray {
  //! The one-dimensional STL vector which actually holds the data
  vector<E> A;

  //! Used for computing fast offsets
  vector<int> Offsets;

  //! Gives the limit for each index: 0..Dimensions[i]-1
  vector<int> Dimensions;

  //! The dimension of the multi-dimensional array
  int Dimension;

  //! Number of elements in the array
  int Size;

 public:
  //! Maximum allowable array size (default = 10 million)
  int MaxSize;
  
  //! Constructor with default assignment of x to each element
  MultiArray(const vector<int> &dims, const E &x);

  //! Constructor with no default assignment
  MultiArray(const vector<int> &dims);

  //! Constructor with no initialization
  MultiArray() {};
  ~MultiArray() {};

  //! This can be used for access or assignment (e.g., ma[indices] = 1).
  inline E& operator[](const vector<int> &indices);

  //! Get the next element (used as an iterator).  Return true if at end.
  inline bool Increment(vector<int> &indices);

  //! This will not work correctly unless dimensions are preset correctly
  friend istream& operator>> (istream &is, MultiArray &ma) 
    { is >> ma.A; return is; }

  //! Just print out the vector
  friend ostream& operator<< (ostream &os, const MultiArray &ma)
    { os << ma.A; return os; }
};

 
#endif
