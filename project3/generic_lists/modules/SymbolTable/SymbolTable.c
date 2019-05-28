#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "SymbolTable.h"
#include "list.h"			// στο SymbolTable.h γίνεται include μόνο το list_types.h, οπότε χρειζόμαστε και το list.h



STTable STCreate() {
	return LLCreate();
}

int STSize(STTable table) {
	return LLLength(table);
}

static int compare_llitems(LLItem a, LLItem b) {
	return strcmp(a.st_pair.key, b.st_pair.key);
}

int STGet(STTable table, STKey key, STItem *pitem) {
	STPair pair = { .key = key };
	LLNode node = LLFind(table, (LLItem){ .st_pair = pair }, compare_llitems);
	if(node == LL_NIL)
		return 0;

	*pitem = LLGetItem(table, node).st_pair.item;
	return 1;
}

STItem STGetEx(STTable table, STKey key) {  // return existing, **FAILS** if doesn't exists
	STItem item;
	assert(STGet(table, key, &item));
	return item;
}

void STInsert(STTable table, STKey key, STItem item) {
	STRemove(table, key);

	STPair pair = { .key = strdup(key), .item = item };
	LLInsertAfter(table, LL_NIL, (LLItem){ .st_pair = pair });
}

void STRemove(STTable table, STKey key) {
	STPair pair = { .key = key };
	LLNode node = LLFind(table, (LLItem){ .st_pair = pair }, compare_llitems);
	if(node != LL_NIL)
		LLRemove(table, node);
}

void STVisit(STTable table, STVisitFunc visit) {
	LLNode node = LL_NIL;
	while((node = LLNext(table, node)) != LL_NIL) {
		STPair pair = LLGetItem(table, node).st_pair;
		visit(table, pair.key, pair.item);
	}
}

// used by STDestroy
static void destroy_keys(LLList list, LLNode node) {
	free(LLGetItem(list, node).st_pair.key);
}

void STDestroy(STTable table) {
	LLVisit(table, destroy_keys);		// free keys
	LLDestroy(table);
}