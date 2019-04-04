
// sequential list implementation

#include <stdlib.h>
#include <stdio.h>

#include "list.h"


LstList LstCreate(int length) {
	LstList list;
	list.items = malloc(sizeof(LstItem) * length);
	list.length = length;
	return list;
}

void LstDestroy(LstList list) {
	free(list.items);
}

int LstLength(LstList list) {
	return list.length;
}

LstItem LstGet(LstList list, int pos) {
	if(pos < 0 || pos >= list.length) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}
	return list.items[pos];
}

void LstSet(LstList list, int pos, LstItem item) {
	if(pos < 0 || pos >= list.length) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}
	list.items[pos] = item;
}