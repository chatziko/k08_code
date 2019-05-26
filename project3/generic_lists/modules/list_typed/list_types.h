#pragma once

// Στο αρχείο αυτό (list_types.h) βάζουμε τα βασικά types για λίστες: LLList && LLNode

// Το πλεονέκτημα είναι ότι list_types.h δεν έχει _κανένα_ .h dependency, οπότε μπορούμε να κάνουμε
// #include "listy_types.h" οπουδήποτε χωρίς να προκαλέσουμε κυκλικό include!

// information hiding: ο χρήστης δεν χρειάζεται να γνωρίζει τί υπαρχει μέσα στο struct.
// Πέρα από το information hiding, η χρήση "incomplete" structs μας επιτρέπει να ορίσουμε
// το LLNode χωρίς να ξέρουμε το LLItem, αποφεύγοντας τα κυκλικά includes

typedef struct ll_node *LLNode;					// LLNode is a pointer to "struct lst_node"
typedef LLNode LLList;							// LLList is just an LLNode (we use a dummy node to represent the whole list)