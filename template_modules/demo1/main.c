#include <stdio.h>
#include <string.h>

#include "list.h"

using namespace list;			// just write Foo instead of list::Foo


using CStr = const char*;		// constant string

int compare_strings(CStr a, CStr b) {
	return strcmp(a, b);
}

int main() {
	// A simple demo of a list of strings

	List<CStr> list = Create<CStr>(5);

	Set(list, 0, "Tyrion");
	Set(list, 1, "Jaime");
	Set(list, 2, "Cercei");
	Set(list, 3, "Daenerys");
	Set(list, 4, "Jon");

	printf("Find Tyrion: %d\n", Find<CStr>(list, "Tyrion", compare_strings));
	printf("Find Ned: %d\n", Find<CStr>(list, "Ned", compare_strings));
}