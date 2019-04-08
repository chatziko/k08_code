// list implementation using a fixed-length array

// types: sequential implementation ////////////////////////////////////
//
template<typename T>
struct List {
	int length;							// store the length
	T *items;							// and an array of Ts
};
// Note: in C++ "struct Foo" can be used as just "Foo"! No need for a separate "typedef struct Foo Foo;"


// functions ////////////////////////////////////////////////////////

template<typename T>
List<T> Create(int length) {
	List<T> list;
	list.items = (T*)malloc(sizeof(T) * length);
	list.length = length;
	return list;
}

template<typename T>
void Destroy(List<T> list) {
	free(list.items);
}

template<typename T>
int Length(List<T> list) {
	return list.length;
}

template<typename T>
T Get(List<T> list, int pos) {
	if(pos < 0 || pos >= list.length) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}
	return list.items[pos];
}

template<typename T>
void Set(List<T> list, int pos, T item) {
	if(pos < 0 || pos >= list.length) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}
	list.items[pos] = item;
}