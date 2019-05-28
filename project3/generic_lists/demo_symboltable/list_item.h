#pragma once // modern include guard

// This file is part of demo_union
// This demo uses typed lists, so we need to set the LLItem properly.

#include "SymbolTable.h"

typedef union {
	char *string;
	int	integer;
	LLList list;
	STPair st_pair;
} LLItem;
