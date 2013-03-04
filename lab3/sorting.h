//
//  CSci 115
//  sorting.h
//
//  Function declarations.
//
//  The student must implement the mergesort functions.
//
//  Do not modify.
//

typedef int Item;
// Do not rely on Item being an int.

int key(Item a);
// Returns the key value for Item a.

bool lessThan(Item a, Item b);
// Returns true if the key of Item a is less than the key of Item b.

/***********************************\
*  Mergesort Function Declarations  *
\***********************************/

void mergesort_normal  (Item * A, int p, int r);
void mergesort_bitonic (Item * A, int p, int r);
void merge_normal (Item * A, int, int, int);
void merge_bitonic (Item * A, int, int, int);
