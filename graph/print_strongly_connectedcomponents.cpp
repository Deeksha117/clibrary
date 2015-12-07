#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <stdlib.h>

using namespace std;

#define SIZE 10004
/*
Reports strongly connected components of a graph
*/
struct node
{
	int data;
	struct node *next;
}*temp,*ref;

int set[SIZE];
static int count=0;;
stack <int> mystack;
struct node *g1[SIZE],*g2[SIZE];

void printgraph(int n)
{ int i;
	for (i = 1; i <=n; ++i)
		{temp=g1[i];
			while(temp)
				{printf("%d %d\n",i,temp->data);temp=temp->next;}
		}
}

void dfs(int start)
{
	mystack.push(start);

	while(!mystack.empty())
	{
				temp=g1[mystack.top()];
				//printf("%d\n",mystack.top() );
				set[mystack.top()]=1;
				mystack.pop();

				while(temp->next!=NULL)
				{	
					//printf("hello\n");
					temp=temp->next;
					//printf("data: %d\n",temp->data);
					if(set[temp->data]==0)
					{
						mystack.push(temp->data);	
					}
				}
	}

	mystack.push(start);
	count++;
	printf("Component\n");
	while(!mystack.empty())
	{
				temp=g2[mystack.top()];
				printf("%d\n",mystack.top() );
				set[mystack.top()]=2;
				mystack.pop();

				while(temp->next!=NULL)
				{	
					//printf("hello\n");
					temp=temp->next;
					//printf("data: %d\n",temp->data);
					if(set[temp->data]==1)
					{
						mystack.push(temp->data);
						//cout<<temp->data<<endl;
						count++;
						
					}

				}
	}

}

struct node * insert(long int value)
{
	struct node * par;int FLAG=0;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	
	while(ref!=NULL)
	{ par=ref;
		ref=ref->next;FLAG=1;//printf("hello\n");
	}
	if(FLAG==1)
	{
		par->next=temp;
	}
//	printf("inserted\n");
return temp;
}

int main(int argc, char const *argv[])
{
		int n,m,i,knight,flag;
		
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{	ref=g1[i];
			g1[i]=insert(-1);
			ref=g2[i];
			g2[i]=insert(-1);
		}
		cout<<"edges:"; cin>>m;
		
		int src,dest=1;
		for (i = 1; i <= m; ++i)
		{	
					scanf("%d%d",&src,&dest);
					ref=g1[src];
					insert(dest);
					ref=g2[dest];
					insert(src);
		}
		printgraph(n);
	//printgraph(n);
		
		memset(set,0,sizeof(set));
		count=0;
	//int j=6;
	//while(j>0)	
		while(count<n)
		{
			dfs(dest);
			for (i = 1; i <=n; ++i)
			{	if(set[i]!=2)
				{dest=i;set[i]=0;}
			}
			//j--;
		}
	return 0;
}
