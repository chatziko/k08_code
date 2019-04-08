#include <stdio.h>
#include <string.h>

#include "point.h"

// A simple demo that uses _in the same program)
// - list of strings
// - list of ints
// - list of doubles (via point)

using namespace list;			// just write Foo instead of list::Foo

using CStr = const char*;		// constant string


int compare_strings(CStr a, CStr b) {
	return strcmp(a, b);
}

int compare_ints(int a, int b) {
	return a - b;
}

void string_demo() {
	printf("\n\nstring demo\n-----------------------\n");

	List<CStr> list = Create<CStr>(5);

	Set(list, 0, "Tyrion");
	Set(list, 1, "Jaime");
	Set(list, 2, "Cercei");
	Set(list, 3, "Daenerys");
	Set(list, 4, "Jon");

	printf("Find Tyrion: %d\n", Find<CStr>(list, "Tyrion", compare_strings));
	printf("Find Ned: %d\n", Find<CStr>(list, "Ned", compare_strings));
}

void int_demo() {
	printf("\n\nint demo\n-----------------------\n");

	List<int> list = Create<int>(5);

	for(int i = 0; i < 5; i++)
		Set(list, i, i);

	printf("Find 2: %d\n", Find<int>(list, 2, compare_ints));
}

void point_demo() {
	printf("\n\npoint demo\n-----------------------\n");

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

int main() {
	string_demo();
	int_demo();
	point_demo();
}