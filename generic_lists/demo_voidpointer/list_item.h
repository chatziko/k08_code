#pragma once // modern include guard

// This file is part of demo_voidpointer
//
// demo2 uses typed lists, so we need to set the LLItem properly.
//
// But we need to use _both_ string and int lists, so the solution is void*

typedef void *LLItem;
