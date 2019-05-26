#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

// list implementation


// auxiliary function to create a new node with a given next
//
LLNode NewNode(LLNode next) {
	LLNode node = (LLNode)malloc(sizeof(*node));
	node->next = next;
	return node;
}


LLList LLCreate(int item_size) {
	LLList list = {
		.dummy = NewNode(NULL),
		.item_size = item_size
	};
	return list;
}

void LLDestroy(LLList list) {
	LLNode node = list.dummy;
	while(node != NULL) {
		LLNode next = node->next;		// get this before free()!
		free(node->item);				// don't forget to free the item, not just the node!
		free(node);
		node = next;
	}
}

int LLLength(LLList list) {
	// start from the first _real_ node, count them
	int res = 0;
	for(LLNode node = list.dummy->next; node != NULL; node = node->next)
		res++;
	return res;
}

LLNode LLNext(LLList list, LLNode node) {
	return node == NULL ? list.dummy->next : node->next;
}

void *LLGetItem(LLList list, LLNode node) {
	assert(node != NULL);
	return node->item;
}

LLNode LLInsertAfter(LLList list, LLNode node, void *item) {
	if(node == NULL)		// if node is null then
		node = list.dummy;	// insert after the dummy! (

	node->next = NewNode(node->next);
	node->next->item = malloc(list.item_size);
	memcpy(node->next->item, item, list.item_size);
	return node->next;
}

void LLRemove(LLList list, LLNode node) {
	// find the previous one (TODO: speedup using doubly linked list)
	for(LLNode prev = list.dummy; prev->next != NULL; prev = prev->next)
		if(prev->next == node) {
			prev->next = node->next;
			free(node);
			break;
		}
}

LLNode LLFind(LLList list, void *item, LLCompareFunc compare) {
	// iterate over list
	for(LLNode node = list.dummy->next; node != NULL; node = node->next)
		if(compare(item, node->item) == 0)
			return node;		// found it

	return NULL;	// it's not here
}

void LLVisit(LLList list, LLVisitFunc visit) {
	// iterate over list
	for(LLNode node = list.dummy->next; node != NULL; node = node->next)
		visit(list, node);
}