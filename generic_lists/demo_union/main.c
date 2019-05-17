#include <stdio.h>
#include <string.h>

#include "list.h"

// Demo που δείχνει τη χρήση μια typed list με διαφορετικά types
// στο ίδιο πρόγραμμα, θέτωντας LLItem = union από string/int



// ------------ strings -----------------

int compare_strings(LLItem a, LLItem b) {	// the params are unions!
	return strcmp(a.string, b.string);		// use the string part
}

void visit_string(LLList list, LLNode node) {
	printf("%s\n", LLGetItem(list, node).string);	// use the string part
}

LLList create_string_list() {
	char* strings[] = { "A", "B", "C", "D", "E" };

	LLList list = LLCreate();
	LLNode node;

	for(int i = 0; i < 5; i++) {
		LLItem item = { .string = strings[i] };		// initialize the union with a string
		node = LLInsertAfter(list, node, item);
	}

	return list;
}

void demo_string() {
	// list of strings
	LLList list = create_string_list();

	LLItem item;	// we need an LLItem (union) for LLFind

	item.string = "A";
	printf("A exists?: %d\n", LLFind(list, item, compare_strings) != LL_NIL);
	item.string = "Z";
	printf("Z exists?: %d\n", LLFind(list, item, compare_strings) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_string);

	// Τα items είναι string literals, δεν τα έχουμε κάνει εμείς malloc. Οπότε πρέπει μόνο να κάνουμε free τη λίστα
	LLDestroy(list);
}


// ------------ ints -----------------

LLList create_int_list() {
	LLList list = LLCreate();
	LLNode node = LL_NIL;

	for(int i = 0; i < 5; i++) {
		LLItem item = { .integer = i };			// initialize the union with an integer
		node = LLInsertAfter(list, node, item);
	}

	return list;
}

int compare_ints(LLItem a, LLItem b) {	// params are LLItems (unions)!
	return a.integer - b.integer;		// compare the integer parts
}

void visit_int(LLList list, LLNode node) {
	printf("%d\n", LLGetItem(list, node).integer);	// get the integer part
}

void demo_int() {
	// list of int
	LLList list = create_int_list();

	LLItem item;	// we need an LLItem (union) for LLFind

	item.integer = 4;
	printf("4 exists?: %d\n", LLFind(list, item, compare_ints) != LL_NIL);
	item.integer = 7;
	printf("7 exists?: %d\n", LLFind(list, item, compare_ints) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_int);

	LLDestroy(list);
}


int main() {
	demo_string();
	demo_int();
}