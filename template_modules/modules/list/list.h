#pragma once // modern include guard

// A (very) simple list
//
// Two implementations are given:
// - sequential
//   * constant-time Get/Set/Length
//   * fixed-length
// - linked
//   * linear-time Get/Set/Length
//   * variable length
//
// To select implementation: make LST_IMPL=[sequential|linked]

#include <stdio.h>
#include <stdlib.h>

namespace list{							// all our code (not external #includes) inside a namespace "list"

template<typename T>
using CompareFunc = int (*)(T a, T b);	// CompareFunc<T>: type of functions that compare two T objects

// Template functions go to .h files, not .c files! But we can have different implementations.
//
#ifdef LST_IMPL_SEQUENTIAL				// LST_IMPL_SEQUENTIAL is set in make.inc, when LST_IMPL=sequential is passed
	#include "sequential.h"				// sequential implementation
#else
	#include "linked.h"					// linked implementation
#endif

#include "common.h"						// common functions for both implementations (include last so that types are defined!)

} // namespace list

// No need to declared functions here (all code is inside .h files!), but provide some documentation
// so that the user can quickly see what functions we provide!


/////////////////////////////////// Documentation ///////////////////////////////////////
//
// TYPES
//
// List<T>
// 
//   a list containing items of type T
//
// FUNCTIONS
// 
// List<T> Create<T>(int length)
// 
//   creates a new list (length is only used in the sequential implementation)
// 
// void Destroy<T>(List<T> list)
// 
//    destroys a list
// 
// int Length<T>(List<T> list)
// 
//   returns the length of a list
// 
// T Get<T>(List<T> list, int pos)
// 
//    returns the pos-th element (error if out of bounds)
// 
// void Set<T>(List<T> list, int pos, T item)
// 
//    sets the pos-th element (sequential: error if out of bounds)
// 
// int Compare<T>(List<T> list1, List<T> list2, CompareFunc<T> compare)
// 
//   return 0 if list1 and list2 are equal (equal length, equal elements)
//   compare(item1, item2) should return 0 if item1 == item2
// 
// int Find<T>(List<T> list, T item, CompareFunc<T> compare)
//
//   returns the index of the first occurance of item in the list (or -1 if no occurence exists)
//   compare(item1, item2) should return 0 if item1 == item2
//
//////////////////////////////////////////////////////////////////////////////////////////