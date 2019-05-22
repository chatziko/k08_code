
#include "pet.h"


int main() {
	// create 2 pets, make them talk

	Pet pet1 = PetCreate();
	Pet pet2 = PetCreate();

	PetTalk(pet1);
	PetTalk(pet2);
}