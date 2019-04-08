// list implementation using a variable-length linked list

// types: linked implementation ///////////////////////////////////
//
template<typename T>
struct node {
	T item;
	struct node<T> *next;
};

template<typename T>
using Node = struct node<T>*;

// We use a dummy node as first for every list. The whole list (List) is
// represented by the dummy node, so List<T> is simply Node
template<typename T>
using List = Node<T>;



// functions ////////////////////////////////////////////////////////


// auxiliary function to create a new node with a given next
// static so that it is completely hidden from the outside world
//
template<typename T>
Node<T> NewNode(Node<T> next) {
	Node<T> node = (Node<T>)malloc(sizeof(*node));
	node->next = next;
	return node;
}

template<typename T>
List<T> Create(int maxlen) {
	return NewNode<T>(NULL);			// empty list represented by a dummy node
}

template<typename T>
void Destroy(List<T> list) {
	Node<T> node = list;
	while(node != NULL) {
		Node<T> next = node->next;		// get this before free()!
		free(node);
		node = next;
	}
}

template<typename T>
int Length(List<T> list) {
	// start from the first _real_ node, count them
	int res = 0;
	for(Node<T> node = list->next; node != NULL; node = node->next)
		res++;
	return res;
}

template<typename T>
T Get(List<T> list, int pos) {
	// TODO: maybe we can do this faster?
	if(pos < 0 || pos >= Length(list)) {
		printf("out of bounds: %d\n", pos);
		exit(-1);	// failure, just die
	}

	Node<T> node = list->next;		// start from the first _real_ node, advance pos times
	for(int i = 0; i < pos; i++)
		node = node->next;
	return node->item;
}

template<typename T>
void Set(List<T> list, int pos, T item) {
	Node<T> node = list;

	for(int i = 0; i < pos+1; i++) {	// we start from the dummy, so we need pos+1 advances to reach the node
		if(node->next == NULL)
			node->next = NewNode<T>(NULL);	// the node hasn't been create it yet, do it now
		node = node->next;
	}
	node->item = item;
}