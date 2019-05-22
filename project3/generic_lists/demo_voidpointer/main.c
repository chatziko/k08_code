#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"

// Demo που δείχνει τη χρήση μια typed list με διαφορετικά types
// στο ίδιο πρόγραμμα, θέτωντας LLItem = void*



// ------------ strings -----------------

int compare_strings(void *a, void *b) {	// the params need to be void* !
	return strcmp(a, b);	// auto cast void* -> char*
}

void visit_string(LLList list, LLNode node) {
	char *s = LLGetItem(list, node);		// auto cast void* -> char*
	printf("%s\n", s);
}

LLList create_string_list() {
	// Ενα string s είναι pointer char*, η λίστα αποθηκεύει επίσης pointers, αλλά void*.
	// Οπότε μπορoυμε να αποθηκεύσουμε το _ίδιο_ το s στη λίστα, απλά κάνοντάς το cast
	// (το οποίο συχνά το κάνει αυτόματα η C).

	char* strings[] = { "A", "B", "C", "D", "E" };

	LLList list = LLCreate();
	LLNode node;

	for(int i = 0; i < 5; i++)
		node = LLInsertAfter(list, node, strings[i]);

	return list;
}

void demo_string() {
	// list of strings
	LLList list = create_string_list();

	printf("A exists?: %d\n", LLFind(list, "A", compare_strings) != LL_NIL);
	printf("Z exists?: %d\n", LLFind(list, "Z", compare_strings) != LL_NIL);

	LLRemove(list, LLNext(list, LLNext(list, LL_NIL)));		// remove 2nd element
	LLVisit(list, visit_string);

	// Τα items είναι string literals, δεν τα έχουμε κάνει εμείς malloc. Οπότε πρέπει μόνο να κάνουμε free τη λίστα
	LLDestroy(list);
}


// ------------ ints -----------------

LLList create_int_list() {
	// Θέλουμε να αποθηκεύυομε ints, αλλά η λίστα αποθηκεύει pointers (void*).
	// Οπότε δε θα αποθηκεύσουμε τον ίδιο τον ακέραιο, αλλά έναν pointer σε αυτόν!

	LLList list = LLCreate();
	LLNode node = LL_NIL;

	for(int i = 0; i < 5; i++) {
		// ΠΡΟΣΟΧΗ
		// Η λίστα αποθηκεύει μόνο τον pointer, δεν αντιγράφει δεδομένα!
		// Το i είναι τοπική μεταβλητή, άρα χρειαζόμαστε malloc (δεν μπορούμε να βάλουμε item = &i)
		//
		int *item = malloc(sizeof(int));
		*item = i;
		node = LLInsertAfter(list, node, item);		// auto cast int* -> void*
	}

	return list;
}

int compare_ints(void *a, void *b) {
	// Τα a,b είναι στην πραγματικότητα pointers σε int, οπότε φτιάχνουμε πραγματικούς
	// int pointers και τους κάνουμε dereference
	int* ia = a;
	int* ib = b;
	return *ia - *ib;
}

void visit_int(LLList list, LLNode node) {
	// Το item είναι στην πραγματικότητα pointer σε int
	int* item = LLGetItem(list, node);		// auto cast void* -> int*
	printf("%d\n", *item);
}

// Χρησιμοποιείται μαζί με τη visit για να κάνουμε free τα items της λίστας
void free_item(LLList list, LLNode node) {
	free(LLGetItem(list, node));
}

void demo_int() {
	// list of int
	LLList list = create_int_list();

	int i = 4;
	printf("4 exists?: %d\n", LLFind(list, &i, compare_ints) != LL_NIL);
	i = 7;
	printf("7 exists?: %d\n", LLFind(list, &i, compare_ints) != LL_NIL);

	// ΠΡΟΣΟΧΗ: θέλουμε να αφαιρέσουμε το 2ο node, αλλά η λίστα αποθηκεύει απλά ένα int*,
	// είναι δική μας δουλειά να κάνουμε free το item!
	LLNode node = LLNext(list, LLNext(list, LL_NIL));		// 2nd node
	free(LLGetItem(list, node));
	LLRemove(list, node);

	LLVisit(list, visit_int);

	// ΠΡΟΣΟΧΗ
	// Τα items είναι pointers που έχουμε εμείς κάνει malloc. Εμείς πρέπει και να τα κάνουμε free
	LLVisit(list, free_item);
	LLDestroy(list);
}


int main() {
	demo_string();
	demo_int();
}