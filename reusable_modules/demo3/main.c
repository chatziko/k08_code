#include <stdio.h>

#include "stack.h"


int main() {
	StStack stack = StCreate(100);

	StInsert(stack, 5);
	StInsert(stack, 6);
	StInsert(stack, 7);

	printf("remove: %d", StRemove(stack));
	printf(", Empty?: %d\n", StEmpty(stack));

	printf("remove: %d", StRemove(stack));
	printf(", Empty?: %d\n", StEmpty(stack));

	printf("remove: %d", StRemove(stack));
	printf(", Empty?: %d\n", StEmpty(stack));
}