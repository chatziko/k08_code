#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

// Demo που δείχνει τη χρήστη λίστας από strings και ints στο ίδιο πρόγραμμα,
// χρησιμοποιώντας μια template list.


// Στη λίστα θα βάζουμε "constant strings", όπως πχ ένα string literal "A". Στη C++ αυτά έχουν τύπο const char*
//
typedef const char *CStr;			// constant string

// typedefs for easier to write/understand code
typedef LLList<CStr> StringList;
typedef LLNode<CStr> StringNode;

typedef LLList<int> IntList;
typedef LLNode<int> IntNode;



// ------------ strings -----------------

int compare_strings(CStr a, CStr b) {
	return strcmp(a, b);
}

void visit_string(StringList list, StringNode node) {
	printf("%s\n", LLGetItem(list, node));
}

StringList create_string_list() {
	CStr strings[] = { "A", "B", "C", "D", "E" };

	StringList list = LLCreate<CStr>();		// <CStr> needed, cannot infer type
	StringNode node = LL_NIL;

	for(int i = 0; i < 5; i++)
		node = LLInsertAfter(list, node, strings[i]);

	return list;
}

void demo_string() {
	// list of strings
	StringList list = create_string_list();

	printf("A exists?: %d\n", LLFind(list, "A", compare_strings) != LL_NIL);
	printf("Z exists?: %d\n", LLFind(list, "Z", compare_strings) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext<CStr>(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_string);

	LLDestroy(list);
}

// ------------ ints -----------------

int compare_ints(int a, int b) {
	return a - b;
}

void visit_int(IntList list, IntNode node) {
	printf("%d\n", LLGetItem(list, node));
}

IntList create_int_list() {
	IntList list = LLCreate<int>();		// <int> needed, cannot infer type!
	IntNode node = LL_NIL;

	for(int i = 0; i < 5; i++)
		node = LLInsertAfter(list, node, i);

	return list;
}

void demo_int() {
	// list of int
	IntList list = create_int_list();

	printf("4 exists?: %d\n", LLFind(list, 4, compare_ints) != LL_NIL);
	printf("7 exists?: %d\n", LLFind(list, 7, compare_ints) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext<int>(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_int);
}


int main() {
	demo_string();
	demo_int();
}