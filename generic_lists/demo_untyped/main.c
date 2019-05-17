#include <stdio.h>
#include <string.h>

#include "list.h"

// Demo που δείχνει τη χρήση μιας untyped list για αποθήκευση λίστας από strings
// και ints στο ίδιο πρόγραμμα.



// ------------ strings -----------------

int compare_strings(void *a, void *b) {	// the params need to be void* !
	// ΠΡΟΣΟΧΗ
	// Η λίστα αποθηκεύει char*, οπότε μας περνάει pointer σε char* (δηλαδή char**)
	char **ap = a;
	char **bp = b;
	return strcmp(*ap, *bp);
}

void visit_string(LLList list, LLNode node) {
	// ΠΡΟΣΟΧΗ
	// Η λίστα περιέχει char*. Η GetItem επιστρέφει _pointer_ σε char* δηλαδή char**
	char **sp = LLGetItem(list, node);
	printf("%s\n", *sp);
}

LLList create_string_list() {
	char* strings[] = { "A", "B", "C", "D", "E" };

	LLList list = LLCreate(sizeof(char*));		// a list of char*
	LLNode node;

	// ΠΡΟΣΟΧΗ
	// Η λίστα περιέχει char* οπότε στην LLInsertAfter πρέπει να περάσουμε έναν _pointer_ σε char*
	// (δηλαδή char**) και όχι ένα char*. Δηλαδή &strings[i], όχι strings[i]
	for(int i = 0; i < 5; i++)
		node = LLInsertAfter(list, node, &strings[i]);

	return list;
}

void demo_string() {
	// list of strings
	LLList list = create_string_list();

	char *s = "A";
	printf("A exists?: %d\n", LLFind(list, &s, compare_strings) != LL_NIL);
	s = "Z";
	printf("Z exists?: %d\n", LLFind(list, &s, compare_strings) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_string);

	LLDestroy(list);
}


// ------------ ints -----------------

LLList create_int_list() {
	LLList list = LLCreate(sizeof(int));		// a list of int
	LLNode node = LL_NIL;

	for(int i = 0; i < 5; i++) {
		// Η λίστα αντιγράφει τον ακέραιο που της περνάμε, δεν κρατάει τον pointer!
		// Οπότε μπορούμε απλά να περάσουμε &i κι ας είναι τοπική μεταβλητή!
		node = LLInsertAfter(list, node, &i);
	}

	return list;
}

int compare_ints(void *a, void *b) {
	// Τα a,b είναι pointers σε int, οπότε φτιάχνουμε πραγματικούς int pointers και τους κάνουμε dereference
	int *ia = a;
	int *ib = b;
	return *ia - *ib;
}

void visit_int(LLList list, LLNode node) {
	// Η λίστα περιέχει ints, οπότε η LLGetItem επιστρέφει pointer σε int
	int *ip = LLGetItem(list, node);
	printf("%d\n", *ip);
}

void demo_int() {
	// list of int
	LLList list = create_int_list();

	int i = 4;
	printf("4 exists?: %d\n", LLFind(list, &i, compare_ints) != LL_NIL);
	i = 7;
	printf("7 exists?: %d\n", LLFind(list, &i, compare_ints) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_int);

	LLDestroy(list);		// ολο το memory management γίνεται από το module, δεν κάναμε κάτι εμείς malloc!
}


int main() {
	demo_string();
	demo_int();
}