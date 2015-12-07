#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition (long int A[], long int l, long int h)
{	long int tempo;
    long int x = A[h];
    long int i = (l - 1);
 	long int j;
    for ( j = l; j <= h- 1; j++)
    {
        if (A[j] <= x)
        {
            i++;
            tempo=A[i];
            A[i]=A[j];
            A[j]=tempo;
        }
    }
    tempo=A[i+1];
     A[i+1]=A[h];
     A[h]=tempo;
    return (i + 1);
}
void quickSort(long int A[],long int l, long int h)
{
    if (l < h)
    {        
        long int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}
