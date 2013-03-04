////  <Troy Lonie>
////  <103537249>
////
////  CSci 115
////  Lab 6
////

#include "lab6.h"

void max_heapify(Item * A, int i, int heapsize);
void heapsort(Item * A, int last);
void build_max_heap(Item * A, int heapsize);
void floyd_heapify(Item * A, int i, int heapsize);

void heapsort(Item * A, int last)
{
  build_max_heap(A, last);
  for(int i=last; i>=2; i--)
  {
    exchange(A[1], A[i]);
    last--;
    max_heapify(A, 1, last);
    //floyd_heapify(A, 1, last);
  }
}

void max_heapify(Item * A, int i, int heapsize)
{
  int largest;
  int left = i*2;
  int right = (i*2)+1;
  if( left <= heapsize && lessThan(A[i],A[left]))
    largest = left;
  else largest = i;
  if( right <= heapsize && lessThan(A[largest],A[right]))
    largest=right;
  if(largest!=i)
  {
    exchange(A[i],A[largest]);
    max_heapify(A,largest, heapsize);
  }
}

void floyd_heapify(Item * A, int i, int heapsize)
{
  int left = i*2;
  int right = (i*2)+1;
  while( left <= heapsize )
  {
    if( right <= heapsize && lessThan(A[left],A[right]) )
    {
      exchange(A[right],A[i]);
      i=right;
    }
    else
    {
      exchange(A[left],A[i]);
      i=left;
    }
   left = i*2;
   right = (i*2)+1;
  }

  while( i > 1 && (i/2)!=i )
  {
    if( lessThan( A[i/2],A[i] ) )
    {
      exchange( A[i/2],A[i] );
    }
    i = i/2;
  }
}

void build_max_heap(Item * A, int heapsize)
{
  for( int i=heapsize/2; i>0; i--)
    max_heapify(A, i, heapsize);
    //floyd_heapify(A, i, heapsize);
}













