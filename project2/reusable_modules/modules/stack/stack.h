#pragma once // modern include guard

// A stack, implemented using the list module
//
#include "list.h"		// we need lists

// The stack contains items of type StItem. It's the _user's_ job to define StItem (not ours).
// He should make sure that a "stack_item.h" file is accessible by the compiler and defines StItem
//
#include "stack_item.h"		// StItem should be defined here

// Types
//
// The following declares an "incomplete" struct. The real struct is defined in stack.c,
// the outside world need not know what's there (information hiding).
// StStack is also declared as a pointer to this struct.
//
typedef struct st_stack *StStack;


// Functions
//
StStack StCreate(int maxlen);
int StEmpty(StStack stack);
void StInsert(StStack stack, StItem item);
StItem StRemove(StStack stack);

