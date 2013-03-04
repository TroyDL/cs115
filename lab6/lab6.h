//
//  CSci 115
//  Lab 6
//
//  Function declarations.
//
//  The student must implement the mergesort functions.
//
//  Do not modify.
//

// Do not rely on Item being an int.
class Record;
typedef Record * Item;

// Return the key of Item 'a'.
int key(Item a);

// Return true if the key of Item 'a' is less than the key of Item 'b'.
bool lessThan(Item a, Item b);

// Exchange the contents of Items 'a' and 'b'.
void exchange(Item & a, Item & b);

//  If the key of Item 'b' is less than the key of Item 'a',
//  then exchange the contents of Items 'a' and 'b'.
void compExchange(Item & a, Item & b);


/*********************************\
*  Heapsort Function Declaration  *
\*********************************/

// Heapsort will use a 1-based array instead of a 0-based array.
// You should not access A[0] at any point.
// A[last] is the last element of the array.

void   heapsort       (Item * A, int last);
