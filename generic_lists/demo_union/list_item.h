#pragma once // modern include guard

// This file is part of demo_union
// This demo uses typed lists, so we need to set the LLItem properly.


// Στο πρόγραμμά μας θέλουμε λίστες ακεραίων ή λίστες από strings. Οπότε μπορούμε το LLItem
// να είναι ένα union που περιέχει είτε έναν ακέραιο είτε ένα string.
//
// ΠΡΟΣΟΧΗ: δε θέλουμε λίστες με strings ΚΑΙ ints μαζί. Ενα struct θα αποθήκευε ένα string
// ΚΑΙ ένα int. Εμείς θέλουμε string Η int.

typedef union {
	char* string;	// store strings here
	int integer;	// store ints here
} LLItem;
