#include<stdio.h>
#include<stdlib.h>

struct node
{
	struct node *left;
	char data;
	struct node *right;
};

char ind[]={'a','b','c','d','e','f','g','\0','\0','h'};
int lc[]={1,3,5,-1,9,-1,-1,-1,-1,-1};
int rc[]={2,4,6,-1,-1,-1,-1,-1,-1,-1};

void inorder(struct node *root) {
	if(root!=NULL) {
		inorder(root->left);
		printf("%c ",root->data);
		inorder(root->right);
	}
}

struct node *buildTree(int i)
{
	struct node *temp=NULL;
	if(i!=-1) {
		temp=malloc(sizeof(struct node));
		temp->left=buildTree(lc[i]);
		temp->data=ind[i];
		temp->right=buildTree(rc[i]);
	}
	return temp;
}

int main()
{
	struct node *root=buildTree(0);
	printf("Inorder\n");
	inorder(root);
	printf("\n");
	return 0;
}

/* This method is more efficient than root->left->left...
while writing inorder on paper proceed as the algorithm proceeds*/
