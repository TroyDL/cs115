//
//  Troy Lonie
//  103537249
//  CSci 115
//  Lab 7
//
//  Implementation for Lab 7.
//

#include "lab7.h"
#include <iostream>
using namespace std;
void counting_sort(unsigned int * A, int size, int k, int digit); //prototype

//'r' bits for each run.  Check with r = 4, 8, 16.  Use counting sort.
void LSD_radixSort(unsigned int * A, int size, int r) //r4 for now
{
  int k = 2;
  for( int i = 1; i < r; i++ )
    k *= 2;
  k -= 1; //k should now be (2^r)-1 which is the range needed for counting sort
  int D = (sizeof(unsigned int) * 8); //D contains the bitsize of an unsigned int
  cout << "k=" << k << " r=" << r << " D=" << D << " size=" << size << endl;
  for( int i = 0; i < D; i+=r )
  {
    counting_sort(A, size, k, i); //call counting sort on the first 'r' bits of each value
  }
}

//takes in an array, a digit, a digit size, and the total array size and sorts
void counting_sort(unsigned int * A, int size, int k, int digit) //r is unused at the moment
{
  unsigned int count[k+1]; //count array
  unsigned int * aux = new unsigned int[size]; //copy of a to be shifted and modded
  unsigned int * aux2 = new unsigned int[size]; //copy of a to remain an exact copy
  for( int i=0; i<k+1; i++ )
    count[i]=0; //initialize all of count array's elements to 0
  for( int i=0; i<size; i++ )
  {
    aux[i] = A[i]; //exact copy
    aux2[i]= A[i]; //exact copy 2, crashes here when size is over 1,000,000, inconsistently, more often the higher the size
    aux[i] = aux[i] >> digit; //bitwise shift to the right 'digit' amount of times
    aux[i] = aux[i] % (k+1); //gets rid of currently unused portion of value
  }
  for( int i=0; i<size; i++ )
    count[aux[i]]++;
  for( int i=1; i<=k; i++ )
    count[i]=count[i]+count[i-1];
  for( int j=size-1; j>=0; j-- )
  {
    A[count[aux[j]]-1]=aux2[j];
    count[aux[j]]--;
  }
  delete aux;
  delete aux2;
}













