#include <stdio.h>

#include "point.h"

// A simple demo of the point module.
//
// Note that the code here just uses Points. We don't know
// or care whether Points internally use lists.

int main() {
	Point a = Pnt3D(1, 2, 3);
	Point b = Pnt3D(-2, 3, 0);

	printf("a: "); PntPrint(a); printf("\n");
	printf("b: "); PntPrint(b); printf("\n");
	printf("compare a and a: %d\n", PntCompare(a, a));
	printf("compare a and b: %d\n", PntCompare(a, b));
	printf("distance: %f\n", PntDistance(a, b));

	Point one = PntOne(10);
	Point two = PntScale(one, 2);

	printf("\none: "); PntPrint(one); printf("\n");
	printf("two: "); PntPrint(two); printf("\n");
	printf("distance: %f\n", PntDistance(one, two));
}