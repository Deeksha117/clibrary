#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*given nlnllnll pattern of full binary tree, find depth*/
int i=0;

int depth(char *arr)
{	int x=0;
	int y=0;
	if(arr[i]=='n')
	{	++i;
		x=depth(arr);
		++i;
		y=depth(arr);
		if(x>y) {return (1+x);}
		else {return (1+y);}
	}
	else 
	{
		return 0;
	}
}

int main()
{
	int cases;
	char a[13000];
	scanf("%d",&cases);
	while(cases>0)
	{	i=0;
		scanf("%s",a);
	//	len=strlen(a);
		printf("%d\n",depth(a));
		cases--;
	}

return 0;
}
