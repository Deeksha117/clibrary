#include <stdio.h>
#include <stdlib.h>

//Preorder of BST given, make tree, print postorder

struct elem
{
	struct elem *r;
	struct elem *l;
	long int data;
}*begin;


void postfix(struct elem *head)
{

	if(head->l!=NULL)
	{
		postfix(head->l);
	}
	if(head->r!=NULL)
	{
		postfix(head->r);
	}
	printf("%ld\n",head->data);
}

int main()
{
	long int cases,n,x;
	struct elem *rec[108009];
	scanf("%ld",&cases);
	int top=-1,max=-999,stat;
	struct elem *head=malloc(sizeof(struct elem));
	begin=head;
	int i;
	for (i = 1; i <= cases; ++i)
	{	
		top=-1;max=-999;stat=0;
		head=begin;
		head->l=NULL;
		head->r=NULL;
		scanf("%ld",&n);

		while(n>0)
		{
			stat=0; //status if node is placed into tree 0-placed -1-notplaced
			struct elem *newnode=malloc(sizeof(struct elem));
			scanf("%ld",&x);
			newnode->data=x;
			newnode->l=NULL;
			newnode->r=NULL;

			if(top==-1)			{//First node inserted
					rec[++top]=newnode;
					head=begin;
					head->r=newnode;
					begin=head->r;
				}
			else if(x<max)	//Invalid preorder given eg. 1 2 4 5 3
				{
					//printf("Invalid Preorder");
					stat=-1;
				}
			else if(x<rec[top]->data) //into left subtree
			{
				head=rec[top];
				head->l=newnode;
				rec[++top]=newnode;

			}	
			else if(x>rec[top]->data) //into right subtree
			{
				while(top!=-1 && x>rec[top]->data)
				{
					max=rec[top]->data;
					top--;
				}
				head=rec[top+1];
				head->r=newnode;
				rec[++top]=newnode;
			}
			
			n--;
		}
		if(stat!=-1)
		{
			printf("Case %d:\n",i);
			postfix(begin);
		}
		else
		{
			printf("Case %d:\n-1\n",i);
		}
	}

	return 0;
}