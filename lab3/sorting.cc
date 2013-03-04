//  <Troy Lonie>
//  <103537249>
//  CSci 115
//  Lab 3
//  sorting.cc

#include "sorting.h"
#include <iostream>
using namespace std;
typedef int Item;
// Do not rely on Item being an int.

int key(Item a);
// Returns the key of Item a.

bool lessThan(Item a, Item b);
// Returns true if the key of Item a is less than the key of Item b.

void mergesort_normal          (Item * A, int p, int r)
{
	if( (r-p)>0 ) {
		int q = p + (r-p)/2;
		mergesort_normal( A, p, q);
		mergesort_normal( A, q+1, r);
		merge_normal( A, p, q, r);
	}
}

void merge_normal              (Item * A, int p, int q, int r)
{
	Item temp [r-p+1];
	int i=p;
	int j=q+1;
	int k=0;
	
	while( i<=q && j<=r ){
		if( lessThan( key(A[i]), key(A[j]) ) ){
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
}


/*********************\
*  Bitonic Mergesort  *
\*********************/

void mergesort_bitonic         (Item * A, int p, int r)
{
	if( (r-p)>0 ) {
		int q = p + (r-p)/2;
		mergesort_normal( A, p, q);
		mergesort_normal( A, q+1, r);
		merge_normal( A, p, q, r);
	}
}

void merge_bitonic             (Item * A, int p, int q, int r)
{

	Item temp [r-p+1];
	for(int i=0;i<(r-p);i++){
		temp[i]=333333;
	}
	int i=p;
	int j=q+1;
	int k=0;
	
	while( i<=q && j<=r ){
		if( A[i]<=A[j] ) {
			temp[k]=A[i];
			k++; i++;
		}
		else if( A[i]>=A[j] ) {
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
}
