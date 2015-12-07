#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,N,i,a[1000000],p,j;
	scanf("%d",&t);
	while(t--)
	{
		p=2;	
		scanf("%d",&N);
		//a=(int *)malloc(N*sizeof(int));
		for(i=0;i<N;i++)
			a[i]=0;
		
		i=0;
		while(p<N)
		{	
			if(a[p]==-1)
				break;
			if(a[p]==0)
				a[p]--;
			for(i=p*2;i<N;i+=p)
				a[i]++;
			/*for(i=p;i<N;i++)
				if(a[i]==0)
				{
					p=i;
					break;
				}*/
			p++;
				
		}
		//for(i=0;i<N;i++)
		//	printf("%d ",a[i]);
		
		i=2;j=N-1;
		//printf("1");
		while(i<N && j >0)
		{
			//printf("%d %d \n",i,j);
			
			if(a[i]==-1)
			{
				if(a[j]==-1)
				{
					if(i+j==N)
					{
						printf("%d %d\n",i,j);
						break;
					}
					else if(i+j < N)
						i++;
					else
						j--;
				}
				else
					j--;
			}
			else
				i++;
		}
				
					
	}	
	return 0;
}


