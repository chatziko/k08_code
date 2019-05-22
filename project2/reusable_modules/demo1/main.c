#include <stdio.h>
#include <string.h>

#include "list.h"


int compare_strings(char *a, char *b) {
	return strcmp(a, b);
}

int main() {
	// A simple demo of a list of strings

	LstList list = LstCreate(5);

	LstSet(list, 0, "Tyrion");
	LstSet(list, 1, "Jaime");
	LstSet(list, 2, "Cercei");
	LstSet(list, 3, "Daenerys");
	LstSet(list, 4, "Jon");

	printf("Find Tyrion: %d\n", LstFind(list, "Tyrion", compare_strings));
	printf("Find Ned: %d\n", LstFind(list, "Ned", compare_strings));
}