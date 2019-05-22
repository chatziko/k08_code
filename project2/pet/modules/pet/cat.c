// implement pet as cat

#include <stdio.h>

#include "pet.h"


Pet PetCreate() {
	static double counter = 0;
	return counter++;		// a cat is a double, return a different one every time
}

void PetTalk(Pet cat) {
	printf("cat %f says: meow\n", cat);
}