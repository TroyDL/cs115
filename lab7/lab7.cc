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
void counting_sort(unsigned int * A, int digit, int radix, int size); //prototype
void LSD_radixSort(unsigned int * A, int size, int r);

//'r' bits for each run.  Check with r = 4, 8, 16.  Use counting sort.
void LSD_radixSort(unsigned int * A, int size, int r)
{
  int D = (sizeof(unsigned int) * 8) / r;
  cout << "D = " << D << endl;
  for( int digit = 0; digit < D; digit++ )
  {
    counting_sort(A,digit,r,size);
  }
}

void counting_sort(unsigned int * A, int digit, int radix, int size)
{
  int B[radix]; //create temp storage array
  for( int i=0; i<radix; i++ )
    B[i]=0; //fill array with 0's
  //check each element and copy it into B where the index is equal to the
  //element's specified digit
  for( int i=0; i<size; i++ )
  {

}
