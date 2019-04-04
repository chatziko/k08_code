
// sequential list implementation

#include <stdio.h>
#include <stdlib.h>

#include "list.h"


// auxiliary function to create a new node with a given next
// static so that it is completely hidden from the outside world
//
static LstNode NewNode(LstNode next) {
	LstNode node = malloc(sizeof(*node));
	node->next = next;
	return node;
}


LstList LstCreate(int maxlen) {
	return NewNode(NULL);			// empty list represented by a dummy node
}

void LstDestroy(LstList list) {
	LstNode node = list;
	while(node != NULL) {
		LstNode next = node->next;		// get this before free()!
		free(node);
		node = next;
	}
}

int LstLength(LstList list) {
	// start from the first _real_ node, count them
	int res = 0;
	for(LstNode node = list->next; node != NULL; node = node->next)
		res++;
	return res;
}

LstItem LstGet(LstList list, int pos) {
	// TODO: maybe we can do this faster?
	if(pos < 0 || pos >= LstLength(list)) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}

	LstNode node = list->next;		// start from the first _real_ node, advance pos times
	for(int i = 0; i < pos; i++)
		node = node->next;
	return node->item;
}

void LstSet(LstList list, int pos, LstItem item) {
	LstNode node = list;

	for(int i = 0; i < pos+1; i++) {	// we start from the dummy, so we need pos+1 advances to reach the node
		if(node->next == NULL)
			node->next = NewNode(NULL);	// the node hasn't been create it yet, do it now
		node = node->next;
	}
	node->item = item;
}