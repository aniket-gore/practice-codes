#include<iostream>
#include<vector>
#include<queue>

using namespace std;

typedef struct binarynode{
	int data;
	struct binarynode *left;
	struct binarynode *right;
}binaryNode;

binaryNode * constructBinaryTree(binaryNode *root){
	binaryNode *temp1 = (binaryNode *)malloc(sizeof(binaryNode));
	temp1->data = 0;

	binaryNode *temp2 = (binaryNode *)malloc(sizeof(binaryNode));
	temp2->data = 0;

	binaryNode *temp3 = (binaryNode *)malloc(sizeof(binaryNode));
	temp3->data = 3;

	binaryNode *temp4 = (binaryNode *)malloc(sizeof(binaryNode));
	temp4->data = 4;
	temp4->left = temp4->right = NULL;

	binaryNode *temp5 = (binaryNode *)malloc(sizeof(binaryNode));
	temp5->data = 5;
	temp5->left = temp5->right = NULL;

	binaryNode *temp6 = (binaryNode *)malloc(sizeof(binaryNode));
	temp6->data = 6;
	temp6->left = temp6->right = NULL;

	binaryNode *temp7 = (binaryNode *)malloc(sizeof(binaryNode));
	temp7->data = 7;
	temp7->left = temp7->right = NULL;
	
//	binaryNode *temp8 = (binaryNode *)malloc(sizeof(binaryNode));
//	temp8->data = 8;
//	temp8->left = temp8->right = NULL;

	temp1->left = temp2;
	temp1->right = temp3;
	temp2->left = temp4;
	temp2->right = temp5;
	temp3->left = temp6;
	temp3->right = temp7;
//	temp4->left = temp8;
	return temp1;
}

void inOrderTraversal(binaryNode *root){
	if(root != NULL){
		inOrderTraversal(root->left);
		cout<<"\t"<<root->data;
		inOrderTraversal(root->right);
	}
}

binaryNode *getBinaryNode(int data){
	binaryNode *node = (binaryNode *)malloc(sizeof(binaryNode));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}