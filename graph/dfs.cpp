/*dfs of directed graph from any start node*/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define SIZE 1000
#define default_value 0
int visited[SIZE];
stack <int> mystack;
struct node
{
	int data;
	struct node *next;
}*temp;
struct node *adjacency_list[SIZE];

//insert node in adjacency_list
struct node * insert(int value,struct node *head)
{
	struct node * par=NULL;
	
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=value;
	temp->next=NULL;
	
	while(head!=NULL)
	{ 	par=head;
		head=head->next;//FLAG=1;//printf("hello\n");
	}
	if(par!=NULL)
	{
		par->next=temp;
	}
//	printf("inserted\n");
return temp;
}

void initializeList(int n)					//the list contains its own id as value of head node
{
	for (int i = 0; i <= n; ++i)
	{
		adjacency_list[i]=insert(i,adjacency_list[i]);
	}

}

void printgraph(int n)
{ 	int i;
	for (i = 0; i <=n; ++i)
		{	
			temp=adjacency_list[i];
			while(temp)
				{printf(" %d ->",temp->data);temp=temp->next;}
			cout<<endl;
		}
}


void dfs(int start)	//start is the start node & n is the number of node in graph
{
	mystack.push(start);

	while(!mystack.empty())
	{
				temp=adjacency_list[mystack.top()];
				printf(" %d ->",mystack.top() );
				visited[mystack.top()]=1;
				mystack.pop();
				while(temp->next!=NULL)
				{	
					temp=temp->next;
					if(visited[temp->data]==0)
					{
						mystack.push(temp->data);
					}
				}
	}
	cout<<endl;
}

void deleteall(int n)
{
	int i;
	struct node *head;
	for(i=0;i<=n;i++)
	{	head=adjacency_list[i];
		if(head->next)
		{
			temp=head;
			head=head->next;
			free(temp);
		}
		adjacency_list[i]=NULL;
	}
	free(head);
}

int main(int argc, char const *argv[])
{
	int edges,vertices,src,dest,startnode;
	cout<<"No of Vertices:";
	cin>>vertices;
	initializeList(vertices);
	cout<<"No of Edges:";
	cin>>edges;
	cout<<"Enter Edges:";
	cout<<"Src Dest"<<endl;
	while(edges>0)
	{
		cin>>src>>dest;
		insert(dest,adjacency_list[src]);	//Insert dest to adjancency list of src
		edges--;
	}
	cout<<"---printing graph---"<<endl;
	printgraph(vertices);
	cout<<"Input Startnode for DFS";
	cin>>startnode;
	dfs(startnode);
	deleteall(vertices);
	return 0;
}