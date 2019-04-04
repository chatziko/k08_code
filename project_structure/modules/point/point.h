#pragma once // modern include guard


// A module for working with n-dimentional points
// 
// Implemented as lists (use make LST_IMPL=[linked,sequential] to choose the implementation
//
#include "list.h"


// Types
//
typedef LstList Point;		// out Points are really just lists (but the user shouldn't care about this)


// Functions
//
//
// creates an n-dimentional 1-point (i.e. having n coordinates, all 1)
//
Point PntOne(int n);

// Easy creation of a 2d-point
//
Point Pnt2D(double x, double y);

// Easy creation of a 3d-point
//
Point Pnt3D(double x, double y, double z);

// returns the dimention of a point
int PntGetDim(Point point);

// returns the i-th coordinate of a point
double PntGetCoord(Point point, int i);

// sets the i-th coordinate of a point
void PntSetCoord(Point point, int i, double value);

// adds two n-dimentional points
Point PntAdd(Point a, Point b);

// scales a point by a scalar factor
Point PntScale(Point point, double factor);

// returns the euclidean norm of a point  (https://en.wikipedia.org/wiki/Norm_(mathematics)#Euclidean_norm)
double PntNorm(Point point);

// returns the (Euclidean) distance between two points
double PntDistance(Point a, Point b);

// prints a point the (Euclidean) distance between two points
void PntPrint(Point point);

// return 0 if a == b, non-0 otherwize
int PntCompare(Point a, Point b);