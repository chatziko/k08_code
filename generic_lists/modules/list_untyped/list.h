#pragma once // modern include guard

// A simple untyped linked list
//
// Τα items της λίστας είναι _untyped_, δεν γνωρίζουμε τον τύπο τους (δεν υπάρχει δηλαδή LLItem).
// Αντί αυτού, ξέρουμε μόνο το _μέγεθος_ item_size του τύπου (όρισμα στην Create). Η Insert παίρνει ένα
// pointer στο item (void* αφού δεν ξέρουμε τον τύπο) και κάνει copy item_size bytes από εκεί.
// Η GetItem επιστρέφει pointer στο item (όχι το ίδιο το item)


#define LL_NIL NULL					// A "Nil" node is just NULL

// Types

struct ll_node {
	void* item;							// pointer to our item (whose type is unknown)
	struct ll_node *next;
};

// "using" is just like typedef, but it can create template types!
//
typedef struct ll_node* LLNode;			// LLNode is a pointer to "struct lst_node"
typedef struct {						// LLList is a struct
	LLNode dummy;						// we use a dummy node, store it here
	int item_size;						// the size of our items
} LLList;

typedef int (*LLCompareFunc )(void*, void*);	// LLCompareFunc: type of functions that compare two items
typedef void (*LLVisitFunc )(LLList, LLNode);	// LLVisitFunc: type of functions that visit a node


// Function declarations

// creates a new list. The item is untyped so we need to know its size!

LLList LLCreate(int item_size);

// destroys a list

void LLDestroy(LLList list);

// returns the length of a list

int LLLength(LLList list);

// returns the node after 'node'. Use node = LL_NIL to get the first.

LLNode LLNext(LLList list, LLNode node);

// Returns a pointer to the data

void *LLGetItem(LLList list, LLNode node);

// Inserts node after given one and returns it. Use node = LL_NIL to insert as first.

LLNode LLInsertAfter(LLList list, LLNode node, void *item);

// Removes a node

void LLRemove(LLList list, LLNode node);

// Returns a node that matches the given item (or Nil if not found)

LLNode LLFind(LLList list, void *item, LLCompareFunc compare);

// Calls visit(list, node) on every node

void LLVisit(LLList list, LLVisitFunc visit);
