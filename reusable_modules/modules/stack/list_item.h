#pragma once // modern include guard

// This file is part of the stack module.
//
// We use lists, so we need to set the LstItem properly.
// The list will store the elements of the stack, which
// have type StItem, so...

#include "stack_item.h"		// we need to know what StItem is, it is defined here!

typedef StItem LstItem;		// store stack items (type StItem) in the list