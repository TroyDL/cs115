//
//  CSci 115
//  Lab 5
//  lab5.h
//
//  Header file for Lab 5.
//
//
//  Do not modify.
//

#include <stdio.h>
#include <iostream>

using namespace std;

//  Compute the number of 2-element subsets of A whose sum is equal to s.
//  Your function must be in o(n^2).
int     lab5a       (int A[], int n, int s);

//  Print the sets of 2 indices of A for those whose sum is equal to s.
void    lab5b       (int A[], int n, int s);


//  Challenge: Can you solve the 3-element case instead of 2 elements?
//  Use the run-time option '-3' to call these instead.
int     lab5a3      (int A[], int n, int s);
void    lab5b3      (int A[], int n, int s);
