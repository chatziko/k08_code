#include <assert.h>
#include <stdlib.h>

#include "list.h"

// list implementation


// auxiliary function to create a new node with a given next
//
LLNode NewNode(LLNode next) {
	LLNode node = (LLNode)malloc(sizeof(*node));
	node->next = next;
	return node;
}


LLList LLCreate() {
	return NewNode(NULL);			// empty list represented by a dummy node
}

void LLDestroy(LLList list) {
	LLNode node = list;
	while(node != NULL) {
		LLNode next = node->next;		// get this before free()!
		free(node);
		node = next;
	}
}

int LLLength(LLList list) {
	// start from the first _real_ node, count them
	int res = 0;
	for(LLNode node = list->next; node != NULL; node = node->next)
		res++;
	return res;
}

LLNode LLNext(LLList list, LLNode node) {
	return node == NULL ? list->next : node->next;
}

LLItem LLGetItem(LLList list, LLNode node) {
	assert(node != NULL);
	return node->item;
}

LLNode LLInsertAfter(LLList list, LLNode node, LLItem item) {
	if(node == NULL)		// if node is null then
		node = list;		// insert after the dummy! (

	node->next = NewNode(node->next);
	node->next->item = item;
	return node->next;
}

void LLRemove(LLList list, LLNode node) {
	// find the previous one (TODO: speedup using doubly linked list)
	for(LLNode prev = list; prev->next != NULL; prev = prev->next)
		if(prev->next == node) {
			prev->next = node->next;
			free(node);
			break;
		}
}

LLNode LLFind(LLList list, LLItem item, LLCompareFunc compare) {
	// iterate over list
	for(LLNode node = list->next; node != NULL; node = node->next)
		if(compare(item, node->item) == 0)
			return node;		// found it

	return NULL;	// it's not here
}

void LLVisit(LLList list, LLVisitFunc visit) {
	// iterate over list
	for(LLNode node = list->next; node != NULL; node = node->next)
		visit(list, node);
}