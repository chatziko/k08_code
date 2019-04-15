#include <stdlib.h>
#include <assert.h>

#include "stack.h"


// The real struct. Only this file needs to know it!
//
struct st_stack {
	int count;		// we need to keep how many items we current have in the stack
	LstList list;	// and the list containing the items
};


StStack StCreate(int maxlen) {
	StStack stack = malloc(sizeof(*stack));
	stack->count = 0;
	stack->list = LstCreate(maxlen);
	return stack;
}

int StEmpty(StStack stack) {
	return stack->count == 0;
}

void StInsert(StStack stack, StItem item) {
	LstSet(stack->list, stack->count, item);
	stack->count++;
}

StItem StRemove(StStack stack) {
	assert(!StEmpty(stack));		// terminate if stack is empty

	stack->count--;
	return LstGet(stack->list, stack->count);
}
