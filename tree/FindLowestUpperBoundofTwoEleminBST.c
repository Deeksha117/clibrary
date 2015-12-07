#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
struct node *left;
struct node *right;
long int data;
}*begin,*head;

int main()
{
long int cases,k,m,x,y,val,status=0;
scanf("%ld",&cases);
//struct node *head=malloc(sizeof(struct node));
//head->left=NULL;
//begin=head;
while(cases>0)
{
	scanf("%ld%ld",&m,&k);
	//printf("%ld %ld\n",m,k );

			scanf("%ld",&val);

		 	struct node *nnode=malloc(sizeof(struct node));
			nnode->data=val;nnode->left=NULL;nnode->right=NULL;
			head=nnode;status=1;//printf("head\n");

	while(m>1)
	{	status=0;
		 scanf("%ld",&val);
		begin=head;

		 while(status==0)
		{
			
			if(val>begin->data)
			 {
				if(begin->right!=NULL) {begin=begin->right;}
				else {struct node *nnode=malloc(sizeof(struct node));
				nnode->data=val;nnode->left=NULL;nnode->right=NULL;
				begin->right=nnode;status=1;//printf("right\n");}		
		       	}
		      }
			else if(val<begin->data) {
				if(begin->left!=NULL) {begin=begin->left;}
				else {
				struct node *nnode=malloc(sizeof(struct node));
				nnode->data=val;nnode->left=NULL;nnode->right=NULL;
				begin->left=nnode;status=1;}
			}
		}
		m--;
	}

	while(k>0){
		scanf("%ld%ld",&x,&y);
				
		begin=head;
		while(begin!=NULL)
		{if(begin->data>x && begin->data>y ) {begin=begin->left;}
		 else if(begin->data<x && begin->data<y) {begin=begin->right;}
		 else break;
		}
		printf("%ld\n",begin->data);
		k--;	
		}
	
cases--;
}

return 0;
}
