#include<stdlib.h>
#include<stdio.h>
long int fib(long int n)
{
	if(n==1 || n==2) {return 1;}
	
	return fib(n-1)+fib(n-2);
}
int main()
{
	long int j,sum,temp1=165580141,temp2=267914296;
	scanf("%ld",&j);	
	/*for(j=43;j<1460;j++)
	{
	sum=temp1+temp2;
	temp1=temp2;
	temp2=sum;
	if(sum>9876543210) break;*/
	 printf("%ld\n",fib(j));
return 0;}

