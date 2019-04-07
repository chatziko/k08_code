#pragma once // modern include guard

// A (very) simple list
//
// Two implementations are given:
// - sequential
//   * constant-time Get/Set/Length
//   * fixed-length
// - linked
//   * linear-time Get/Set/Length
//   * variable length
//
// To select implementation: make LST_IMPL=[sequential|linked]

// The list contains items of type LstItem. It's the _user's_ job to define LstItem (not ours).
// He should make sure that a "list_item.h" file is accessible by the compiler and defines LstItem
//
#include "list_item.h"

// Types
// diffent types are used for the sequential and linked implementations!

#ifdef LST_IMPL_SEQUENTIAL					// LST_IMPL_SEQUENTIAL is set in make.inc, when LST_IMPL=sequential is passed
	// types: sequential implementation
	typedef struct {
		int length;							// store the length
		LstItem *items;						// and an array of LstItems
	} LstList;

#else
	// types: linked implementation
	typedef struct lst_node *LstNode;		// LstNode is a pointer to "struct lst_node"
	struct lst_node {
		LstItem item;
		LstNode next;
	};

	// We use a dummy node as first for every list. The whole list (LstList) is
	// represented by the dummy node, so LstList is simply LstNode
	typedef LstNode LstList;
#endif

typedef int (*LstCompareFunc)(LstItem a, LstItem b);	// LstCompareFunc: type of functions that compare 2 LstItems


// Functions
// *independent* from the implementation, so that changing implementation is easy!
//
// creates a new list (length is only used in the sequential implementation)
//
LstList LstCreate(int length);							

// destroys a list
//
void LstDestroy(LstList list);							

// returns the length of a list
//
int LstLength(LstList list);							

// returns the pos-th element (error if out of bounds)
//
LstItem LstGet(LstList list, int pos);

// sets the pos-th element (sequential: error if out of bounds)
//
void LstSet(LstList list, int pos, LstItem item);

// return 0 if list1 and list2 are equal (equal length, equal elements)
// compare(item1, item2) should return 0 if item1 == item2
//
int LstCompare(LstList list1, LstList list2, LstCompareFunc compare);

// Returns the index of the first occurance of item in the list (or -1 if no occurence exists)
// compare(item1, item2) should return 0 if item1 == item2
//
int LstFind(LstList list, LstItem item, LstCompareFunc compare);
