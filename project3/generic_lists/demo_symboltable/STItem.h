#pragma once
#include "list_types.h"

// ο τύπος των items του symbol table
typedef union {
	int integer;
	char *string;
	LLList list;
} STItem;