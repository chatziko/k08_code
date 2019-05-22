// implement pet as dog

#include <stdio.h>

#include "pet.h"


Pet PetCreate() {
	static int counter = 0;
	return counter++;		// a dog is an int, return a different one every time
}

void PetTalk(Pet dog) {
	printf("dog %d says: woof\n", dog);
}
