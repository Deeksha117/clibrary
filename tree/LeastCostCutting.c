#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Horizontal & vertical cutting of rectangle into sqares with least cost. Given cost of each cut at every 1 unit on piece of rectangle
*/
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
 long int ma[1000009],na[1000009];
void quickSort(long int A[],long int l, long int h)
{
    if (l < h)
    {        
        long int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1);  
        quickSort(A, p + 1, h);
    }
}


int main()
{
	long int cases,m,n,i;
	long int mct,nct,h=1,v=1,cost=0;
	scanf("%ld",&cases);
	while(cases>0)
	{	
		scanf("%ld%ld",&m,&n);
		for(i=0;i<m-1;i++)
		{
			scanf("%ld",&ma[i]);
		}
		for(i=0;i<n-1;i++)
		{
			scanf("%ld",&na[i]);
		}
		quickSort(ma,0,m-1);
		
		quickSort(na,0,n-1);
		
		mct=m-1,nct=n-1,h=1,v=1,cost=0;
		for(i=0;i<m+n-2;i++)
		{
			//printf("%ld %ld\n",ma[mct],na[nct] );
			if(ma[mct]>na[nct])
			{
				cost=(cost+(v*ma[mct]))%1000000007;
					++h;
					mct--;

			}
			else if (ma[mct]<na[nct])
			{
				cost=(cost+(h*na[nct]))%1000000007;
					++v;
					nct--;

			}
			else 
			{
				if(h<=v)
				{
					cost=(cost+(v*ma[mct]))%1000000007;
					++h;
					mct--;
				}
				else
				{
					cost=(cost+(h*na[nct]))%1000000007;
					++v;
					nct--;
				}


			}
		}
		printf("%ld\n",cost );
		for(i=0;i<1000008;i++)
		{
			ma[i]=0;na[i]=0;
		}
		cases--;
	}
	return 0;
}
