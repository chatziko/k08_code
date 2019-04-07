#pragma once // modern include guard

// An abstract pet module
// Can be implemented as dog or cat.


// enable this flag to implement pet as dog.
// #define PET_IMPL_DOG
//
// Equivalently compile with: gcc -DPET_IMPL_DOG ...


#ifdef PET_IMPL_DOG
	// implement pet as dog
	typedef int Pet;	// dogs are ints
#else
	// implement pet as cat
	typedef double Pet;	// cats are doubles
#endif


// functions
//
Pet PetCreate();
void PetTalk();
