
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "point.h"

// Note: this is just a demo, so no memory is freed. Ever :D



Point PntOne(int n) {
	Point point = LstCreate(n);		// lists are already implemented, life is so easy..
	for(int i = 0; i < n; i++)
		LstSet(point, i, 1);
	return point;
}

Point Pnt2D(double x, double y) {
	Point point = LstCreate(2);
	LstSet(point, 0, x);
	LstSet(point, 1, y);
	return point;
}

Point Pnt3D(double x, double y, double z) {
	Point point = LstCreate(3);
	LstSet(point, 0, x);
	LstSet(point, 1, y);
	LstSet(point, 2, z);
	return point;
}

int PntGetDim(Point point) {
	return LstLength(point);	// easy
}

double PntGetCoord(Point point, int i) {
	return LstGet(point, i);	// easy
}

void PntSetCoord(Point point, int i, double value) {
	LstSet(point, i, value);	// so easy
}

Point PntAdd(Point a, Point b) {
	int n = PntGetDim(a);
	Point point = LstCreate(n);
	
	for(int i = 0; i < n; i++)
		LstSet(point, i, LstGet(a, i) + LstGet(b, i));

	return point;
}

// scales a point by a scalar factor
Point PntScale(Point point, double factor) {
	int n = PntGetDim(point);
	Point newpoint = LstCreate(n);
	
	for(int i = 0; i < n; i++)
		LstSet(newpoint, i, factor * LstGet(point, i));

	return newpoint;
}

// returns the euclidean norm of a point 
// https://en.wikipedia.org/wiki/Norm_(mathematics)#Euclidean_norm
//
double PntNorm(Point point) {
	int n = PntGetDim(point);
	double sum = 0;
	for(int i = 0; i < n; i++) {
		double x = LstGet(point, i);
		sum += x*x;
	}
	return sqrt(sum);
}

// returns the (Euclidean) distance between two points
double PntDistance(Point a, Point b) {
	// the distance between a and b is the norm of (a-b)
	return PntNorm(PntAdd(a, PntScale(b, -1)));
}

void PntPrint(Point point) {
	int n = PntGetDim(point);
	printf("(");
	for(int i = 0; i < n; i++) {
		if(i > 0)
			printf(", ");
		printf("%f", LstGet(point, i));
	}
	printf(")");
}

// auxiliary function that compares 2 doubles.
// CAREFULL: never use == for doubles, but check whether abs(a-b) is small
//
static int CompareDoubles(double a, double b) {
	return abs(a - b) > 1e-6;
}

int PntCompare(Point a, Point b) {
	// We know how to compare lists! Just pass a proper compare function, in our case one that compares doubles.
	return LstCompare(a, b, CompareDoubles);	

	// NOTE: this also works (just a bit slower)
	// return CompareDoubles(PntDistance(a, b), 0);
}
