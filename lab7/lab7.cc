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
void counting_sort(unsigned int * A, unsigned int * B, int K, int size); //prototype

//'r' bits for each run.  Check with r = 4, 8, 16.  Use counting sort.
void LSD_radixSort(unsigned int * A, int size, int r)
{
  int D = (sizeof(unsigned int) * 8) / r;
  cout << "D = " << D << endl;
  for( int i = 0; i < D; i++ )
  {

  }
}


void counting_sort(unsigned int * A, unsigned int * B, int K, int size)
{
  unsigned int *C[K];
  for( int i=0; i<K; i++ )
    C[i]=0;
  for( int j=1; j<size; j++ )
    C[A[j]]=C[A[j]]+1;
  //C[i] now contains the # of elements = to i

}
