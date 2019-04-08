// functions that are common for both list implementations (so that we don't need to write them twice!)

// Note: For the sequential implementation both algorithms below are O(n).
// But maybe for the linked implementation they are O(n^2) ???
// TODO: check this, and maybe provide separate sequential/linked implementations in the future.


template<typename T>
int Compare(List<T> list1, List<T> list2, CompareFunc<T> compare) {

	// This should work for both implementations! If we only use *
	// functions (instead of accessing list1/list2 directly) we should be fine.

	int len = Length(list1);
	if(len != Length(list2))
		return -1;			// different length, so not equal!

	for(int i = 0; i < len; i++)
		if(compare(Get(list1, i), Get(list2, i)) != 0)
			return -1;		// different i-th elements, so not equal!
	
	return 0;	// everything ok, equal!	

}

template<typename T>
int Find(List<T> list, T item, CompareFunc<T> compare) {
	int len = Length(list);
	for(int i = 0; i < len; i++)
		if(compare(item, Get(list, i)) == 0)
			return i;		// found it
	
	return -1;	// it's not here
}
