#pragma once // modern include guard

// A simple symbol table, implemented by a linked list
// VERY inefficient

#include "list_types.h"			// χρειαζόμαστε μόνο το LLList, οπότε το list_types.h αρκεί! (για να αποφύγουμε κυκλικά includes)
#include "STItem.h"				// the user declares STItem here

typedef char *STKey;
typedef LLList STTable;

typedef struct {
	STKey key;
	STItem item;
} STPair;  						// key-item pair, stored in the list

typedef void (*STVisitFunc )(STTable, STKey, STItem);	// STVisitFunc: type of functions that visit

STTable STCreate();
int STSize(STTable table);
int STGet(STTable table, STKey key, STItem *pitem);
STItem STGetEx(STTable table, STKey key);  // return existing, **FAILS** if doesn't exists
void STInsert(STTable table, STKey key, STItem item);
void STRemove(STTable table, STKey key);
void STVisit(STTable table, STVisitFunc visit);
void STDestroy(STTable table);
