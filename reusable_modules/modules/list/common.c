
// functions that are common for both list implementations (so that we don't need to write them twice!)

#include "list.h"


// Note: For the sequential implementation both algorithms below are O(n).
// But maybe for the linked implementation they are O(n^2) ???
// TODO: check this, and maybe provide separate sequential/linked implementations in the future.


int LstCompare(LstList list1, LstList list2, LstCompareFunc compare) {

	// This should work for both implementations! If we only use Lst*
	// functions (instead of accessing list1/list2 directly) we should be fine.

	int len = LstLength(list1);
	if(len != LstLength(list2))
		return -1;			// different length, so not equal!

	for(int i = 0; i < len; i++)
		if(compare(LstGet(list1, i), LstGet(list2, i)) != 0)
			return -1;		// different i-th elements, so not equal!
	
	return 0;	// everything ok, equal!	

}

int LstFind(LstList list, LstItem item, LstCompareFunc compare) {
	int len = LstLength(list);
	for(int i = 0; i < len; i++)
		if(compare(item, LstGet(list, i)) == 0)
			return i;		// found it
	
	return -1;	// it's not here
}
