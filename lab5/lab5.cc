//  Troy Lonie
//  103537249
//  CSci 115
//  Lab 5
//  lab5.cc
//
//  Implementation for Lab 5.
//

#include "lab5.h"
#include <iostream>
#include <stdlib.h>
void mergesort_normal (int A[], int p, int r);
void merge_normal     (int A[], int p, int q, int r);
int bsearch(int A[], int, int, int);

void mergesort_normal          (int A[], int p, int r)
{
  if( (r-p)>0 ) {
    int q = p + (r-p)/2;
      mergesort_normal( A, p, q);
      mergesort_normal( A, q+1, r);
      merge_normal( A, p, q, r);
  }
}
void merge_normal              (int A[], int p, int q, int r)
{
  //int * temp;
  //temp = (int*) malloc (r-p+2 + (r-p+2));
  //temp[r-p+2]='\n';
  int temp[r-p+1];
  int i=p;
  int j=q+1;
  int k=0;
  while( i<=q && j<=r ){
    if( (A[i]) < (A[j]) ) {
      temp[k]=A[i];
      k++; i++;
    }
    else {
      temp[k]=A[j];
      k++; j++;
    }
  }
  while( i>q && k<=(r-p) ){
    temp[k]=A[j];
    k++; j++;
  }
  while( j>r && k<=(r-p) ){
    temp[k]=A[i];
    k++; i++;
  }
  j=p; k=0;
  while( k <= (r-p) ){
    A[j]=temp[k];
    j++; k++;
  }
  //free (temp);
}

int bsearch(int A[], int min, int max, int key)
{
        if(min > max)
                return 99999999;
        int mid = ((max-min)/2) + min;
        if( A[mid]==key )
                return A[mid];
        else if( A[mid] > key )
                return bsearch(A, min, mid-1, key);
        else return bsearch(A, mid+1, max, key);
}


int  lab5a  (int A[], int n, int s)
{
  //int * B;
  //B = (int*) malloc (n+n); //46075
  //cout << "test4" << endl;
  int B[n];
  for(int i = 0; i<n; i++)
  {
    B[i] = A[i];
  }
  mergesort_normal(B, 0, n);
  int num = 0; //proble mis not here
  cout << "after mergesort\n";
  for( int i = 0; i<n; i++)
  {
    if (bsearch(B, i+1, n-1, s-B[i]) != 99999999)
      num++;
  }
  return num;
}

void lab5b  (int A[], int n, int s)
{
  /*int B[n];
  int index1, index2;
  for(int i = 0; i<n; i++)
  {
    B[i] = A[i];
  }
  mergesort_normal(A, 0, n);
  int num = 0;
  for( int i = 0; i<n; i++)
  {
    num = bsearch(A, i+1, n-1, s-A[i]);
    if (num != 99999999)
    {
      for(int k=0;k<n;k++)
      {
        if (A[i]==B[k])
          index1 = k;
        else if (num==B[k])
          index2 = k;
      }
      cout << "(" << index1 << "," << index2 << ")" << endl;
    }
  }
  */
}


/*************\
*  Challenge  *
\*************/

int  lab5a3 (int A[], int n, int s)
{

}

void lab5b3 (int A[], int n, int s)
{

}
