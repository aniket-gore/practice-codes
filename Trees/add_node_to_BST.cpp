#include<iostream>

using namespace std;

typedef struct bstnode{
	int value;
	struct bstnode *left;
	struct bstnode *right;
}BSTNode;

// Function to add a new value to a Binary Search Tree 
void addBSTNode(int value, BSTNode *root) 
{ 
	BSTNode *temp, *prev, *cur; 
	temp = (BSTNode *)malloc(sizeof(BSTNode)); 
	temp->value = value;
	temp->left = NULL; 
	temp->right = NULL; 
	if(root == NULL) 
	{ 
		root = temp; 
	} 
	else 
	{ 
		prev = NULL; 
		cur = root; 
		while(cur) 
		{ 
			prev = cur; 
			cur = (value < cur->value)? cur->left : cur->right; 
		} 
		if(value > prev->value) 
			prev->right = temp; 
		else 
			prev->left = temp; 
	} 
}

void inOrderTraversal(BSTNode *root){
	if(root != NULL){
		inOrderTraversal(root->left);
		cout<<"\t"<<root->value;
		inOrderTraversal(root->right);
	}
}


void preOrderTraversal(BSTNode *root){
	if(root != NULL){
		cout<<"\t"<<root->value;
		preOrderTraversal(root->left);
		preOrderTraversal(root->right);
	}
}