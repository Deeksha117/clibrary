#include<stdio.h>
#include<stdlib.h>

struct node
{
	char data;
	struct node* right;
	struct node* left;
};
		
struct node* newnode(char c)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data = c;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct node* insert(struct node* root,int data)
{
	
	if (root == NULL)
	    root=newnode(data);

	else if(data <= root->data)
		root->left = insert(root->left,data);
	else
		root->right = insert(root->right,data);

	return root;
}

void Preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}

void Postorder(struct node *root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->data);
}


void Inorder(struct node *root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}


int main()
{
	int n,t,i,x;
	struct node* root=NULL;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d",&x);
			root=insert(root,x);
		}
	
		Preorder(root);
		printf("\n");
		Postorder(root);
		printf("\n");
		Inorder(root);
		printf("\n");
	}
	return 0;
}		
	
