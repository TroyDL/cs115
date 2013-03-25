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
  cout << "k=" << k << " r=" << r << " D=" << D << endl;

  for( int i = 0; i < D; i+=r )
  {
    counting_sort(A, size, k, i);
    /*for( int j=0; j<size; j++ )
      cout << " A[" << j << "]=" << A[j];
    cout << " Radix" << endl; */
  }
}

//takes in an array, a digit, a digit size, and the total array size and sorts
void counting_sort(unsigned int * A, int size, int k, int digit) //r is unused at the moment
{
  /*for( int j=0; j<size; j++ )
    cout << " A[" << j << "]=" << A[j];
  cout << " Count-Before" << endl; */
  unsigned int count[k+1]; //count array
  unsigned int aux[size]; //copy of a to be shifted and modulused
  unsigned int aux2[size]; //copy of a to remain an exact copy
  for( int i=0; i<k+1; i++ )
    count[i]=0; //initialize all of count array's elements to 0
  for( int i=0; i<size; i++ )
  {
    //cout << "a[" << i << "]=" << a[i] << endl;
    aux[i]=A[i]; //exact copy
    //cout << "aux[" << i << "]=" << aux[i] << " original" << endl;
    aux[i] = aux[i]>>digit; //bitwise shift to the right 'digit' amount of times
    //cout << "aux[" << i << "]=" << aux[i] << " shifted" << endl;
    aux[i]=aux[i]%(k+1); //gets rid of currently unused digits
    //cout << "aux[" << i << "]=" << aux[i] << " modded" << endl;
    aux2[i]=A[i];
  }
  for( int i=0; i<size; i++ ) //A=[5,9,2,3,1,8] 0-5
    count[aux[i]]++;//C=[0,1,1,1,0,1,0,0,1,1]
  for( int i=1; i<k; i++ )
    count[i]=count[i]+count[i-1]; //C=[0,1,2,3,3,4,4,4,5,6]
  for( int j=size-1; j>=0; j-- )
  {
    A[count[aux[j]]-1]=aux2[j]; //starts at j=5, aux2[5] which is 8 goes into A[ index ] where index = count[aux[j]] where aux[j] = 8 and so count[8]=5 so A[5]
    count[aux[j]]--;//count[8]=5 goes down to 4.  Next one is j=4 which is aux2[4]=1, count[1]=1 so 1 goes into A[1].  problem, should go into A[0]
  }
  /*for( int j=0; j<size; j++ )
    cout << " A[" << j << "]=" << A[j];
  cout << " Count-After" << endl; */
}













