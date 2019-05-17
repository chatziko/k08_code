#pragma once // modern include guard

// A simple linked list

// The list is **typed**: it contains items of type LLItem.
// It's the _user's_ job to define LLItem (not ours).
// He should make sure that a "list_item.h" file is accessible by the compiler and defines LLItem
//
#include "list_item.h"

#define LL_NIL NULL					// A "Nil" node is just NULL

// Types

struct ll_node {
	LLItem item;							// item, of type LLItem
	struct ll_node *next;
};

// "using" is just like typedef, but it can create template types!
//
typedef struct ll_node* LLNode;					// LLNode is a pointer to "struct lst_node"
typedef LLNode LLList;							// LLList is just an LLNode (we use a dummy node to represent the whole list)

typedef int (*LLCompareFunc )(LLItem, LLItem);	// LLCompareFunc: type of functions that compare two LLItem items
typedef void (*LLVisitFunc )(LLList, LLNode);	// LLVisitFunc: type of functions that visit a node


// Function declarations

// creates a new list

LLList LLCreate();

// destroys a list

void LLDestroy(LLList list);

// returns the length of a list

int LLLength(LLList list);

// returns the node after 'node'. Use node = LL_NIL to get the first.

LLNode LLNext(LLList list, LLNode node);

// Returns the item of a non-Nil node

LLItem LLGetItem(LLList list, LLNode node);

// Inserts node after given one and returns it. Use node = LL_NIL to insert as first.

LLNode LLInsertAfter(LLList list, LLNode node, LLItem item);

// Removes a node

void LLRemove(LLList list, LLNode node);

// Returns a node that matches the given item (or Nil if not found)

LLNode LLFind(LLList list, LLItem item, LLCompareFunc compare);

// Calls visit(list, node) on every node

void LLVisit(LLList list, LLVisitFunc visit);
