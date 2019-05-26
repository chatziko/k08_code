#pragma once // modern include guard

#include <assert.h>
#include <stdlib.h>

// list implementation


// auxiliary function to create a new node with a given next
//
template<typename T>
LLNode<T> NewNode(LLNode<T> next) {
	LLNode<T> node = (LLNode<T>)malloc(sizeof(*node));
	node->next = next;
	return node;
}


template<typename T>
LLList<T> LLCreate() {
	return NewNode<T>(NULL);			// empty list represented by a dummy node
}

template<typename T>
void LLDestroy(LLList<T> list) {
	LLNode<T> node = list;
	while(node != NULL) {
		LLNode<T> next = node->next;		// get this before free()!
		free(node);
		node = next;
	}
}

template<typename T>
int LLLength(LLList<T> list) {
	// start from the first _real_ node, count them
	int res = 0;
	for(LLNode<T> node = list->next; node != NULL; node = node->next)
		res++;
	return res;
}

template<typename T>
LLNode<T> LLNext(LLList<T> list, LLNode<T> node) {
	return node == NULL ? list->next : node->next;
}

template<typename T>
T LLGetItem(LLList<T> list, LLNode<T> node) {
	assert(node != NULL);
	return node->item;
}

template<typename T>
LLNode<T> LLInsertAfter(LLList<T> list, LLNode<T> node, T item) {
	if(node == NULL)		// if node is null then
		node = list;		// insert after the dummy! (

	node->next = NewNode(node->next);
	node->next->item = item;
	return node->next;
}

template<typename T>
void LLRemove(LLList<T> list, LLNode<T> node) {
	// find the previous one (TODO: speedup using doubly linked list)
	for(LLNode<T> prev = list; prev->next != NULL; prev = prev->next)
		if(prev->next == node) {
			prev->next = node->next;
			free(node);
			break;
		}
}

template<typename T>
LLNode<T> LLFind(LLList<T> list, T item, LLCompareFunc<T> compare) {
	// iterate over list
	for(LLNode<T> node = list->next; node != NULL; node = node->next)
		if(compare(item, node->item) == 0)
			return node;		// found it

	return NULL;	// it's not here
}

template<typename T>
void LLVisit(LLList<T> list, LLVisitFunc<T> visit) {
	// iterate over list
	for(LLNode<T> node = list->next; node != NULL; node = node->next)
		visit(list, node);
}