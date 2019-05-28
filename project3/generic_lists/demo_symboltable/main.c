#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "SymbolTable.h"


void visit_int(STTable table, STKey key, STItem item) {
	printf("%s => %d\n", key, item.integer);
}

void visit_str(STTable table, STKey key, STItem item) {
	printf("%s => %s\n", key, item.string);
}

void visit_list(STTable table, STKey key, STItem item) {
	printf("%s => list of %d elements\n", key, LLLength(item.list));
}

int main() {
	// symbol table of ints
	STTable table = STCreate();

	STInsert(table, "foo", (STItem){ .integer = 1 });
	STInsert(table, "foo", (STItem){ .integer = 2 });
	STInsert(table, "bar", (STItem){ .integer = 3 });

	STVisit(table, visit_int);

	printf("size: %d\n", STSize(table));
	STDestroy(table);

	// symbol table of strings
	STTable table2 = STCreate();

	STInsert(table2, "foo", (STItem){ .string = "foo" });
	STInsert(table2, "bar", (STItem){ .string = "bar" });

	STVisit(table2, visit_str);
	printf("size: %d\n", STSize(table2));
	STDestroy(table2);

	// symbol table of lists
	STTable table3 = STCreate();

	LLList list = LLCreate();
	LLInsertAfter(list, LL_NIL, (LLItem){ .integer = 1 });

	STInsert(table3, "foo", (STItem){ .list = list });
	STInsert(table3, "bar", (STItem){ .list = list });

	STVisit(table3, visit_list);
	printf("size: %d\n", STSize(table3));
	STDestroy(table3);

}