#pragma once // modern include guard

// A simple linked list

#define LL_NIL NULL					// A "Nil" node is just NULL

// Types (parametrized by T)

template<typename T>				// a template struct! ll_node<T> is a struct cointaining an item of type T
struct ll_node {
	T item;							// item, of type T
	struct ll_node<T> *next;
};

// "using" is just like typedef, but it can create template types!
//
template<typename T> using LLNode = struct ll_node<T>*;					// LLNode is a pointer to "struct lst_node"
template<typename T> using LLList = LLNode<T>;							// LLList is just an LLNode (we use a dummy node to represent the whole list)

template<typename T> using LLCompareFunc = int (*)(T, T);				// LLCompareFunc: type of functions that compare two T items
template<typename T> using LLVisitFunc = void (*)(LLList<T>, LLNode<T>);// LLVisitFunc: type of functions that visit a node


// Function declarations (technically not really needed, but nice to have them for reference)

// creates a new list

template<typename T>
LLList<T> LLCreate();

// destroys a list

template<typename T>
void LLDestroy(LLList<T> list);

// returns the length of a list

template<typename T>
int LLLength(LLList<T> list);

// returns the node after 'node'. Use node = LL_NIL to get the first.

template<typename T>
LLNode<T> LLNext(LLList<T> list, LLNode<T> node);

// Returns the item of a non-Nil node

template<typename T>
T LLGetItem(LLList<T> list, LLNode<T> node);

// Inserts node after given one and returns it. Use node = LL_NIL to insert as first.

template<typename T>
LLNode<T> LLInsertAfter(LLList<T> list, LLNode<T> node, T item);

// Removes a node

template<typename T>
void LLRemove(LLList<T> list, LLNode<T> node);

// Returns a node that matches the given item (or Nil if not found)

template<typename T>
LLNode<T> LLFind(LLList<T> list, T item, LLCompareFunc<T> compare);

// Calls visit(list, node) on every node

template<typename T>
void LLVisit(LLList<T> list, LLVisitFunc<T> visit);




// For template functions, the implementation is also included in the .h file (there are no .c files!).
// But we put it in a separate .h file for better organization, and include it here.
//
#include "list_impl.h"