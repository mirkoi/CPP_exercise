/*
Name: Sort.cpp
Purpose: Quick array sorting
*/

#include "sort.hpp"
#include <iostream>

using namespace std;

inline void change (int& x, int& y)
{
    int z = x; x = y; y = z;
}

int divide(int a[], int n)
{
    int& ref = a[n-1];
    int i = -1;
    int j = n-1;

    while( i<j )
    {
        do i++; while( a[i] < ref );
        do j--; while ( j>=0 && a[j] > ref);
        change(a[i], (i<j)?a[j]:ref);
    }

    return i;

}

void qsort_array ( int a[], int n )
{
    if( n>1 )
    {
        int i =  divide(a,n);
        qsort_array(a, i);
        qsort_array(a+i+1, n-i-1);
    }
}


void sort_slow ( int a[], int n)
{
    for (int i = 0; i< n-1; i++)
    {
        for (int j = 0; j< n-1-i; j++)
        {
            if ( a[j] > a [j+1])
            {
                change(a[j+1], a[j]);

            }
        }
    }
}

void sort_slow_w ( int a[], int n)
{   int i = 0;
    int j = 0;

    while(i<n-1)
    {
      while(j<n-1-i)
      {
         if ( a[j] > a [j+1])
            {
                change(a[j+1], a[j]);

            }
            j++;
      }
      i++;
    }

}
