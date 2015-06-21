#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

//-------------------TODO--------------------------------
binaryNode * findLargestBSTInBinaryTree(binaryNode *root, binaryNode **BSTroot){
	if(root == NULL){
		return NULL;
	}
	static int min_global = INT_MAX;
	static int max_global= INT_MIN;
	binaryNode *left_r = findLargestBSTInBinaryTree(root->left,BSTroot);
	binaryNode *right_r = findLargestBSTInBinaryTree(root->right,BSTroot);
	if(root->data < min_global || root->data > max_global){
		return NULL;
	}
	*BSTroot = root;
	min_global = min(min_global,root->data);
	max_global = max(max_global,root->data);
	return root;
}
/*
int main(){
	binaryNode *root = getBinaryNode(10);
	root->left = getBinaryNode(5);
	root->left->left = getBinaryNode(2);
	root->left->right = getBinaryNode(7);
	root->right = getBinaryNode(15);
	root->right->left = getBinaryNode(11);
	binaryNode * BSTroot;
	binaryNode *temp = findLargestBSTInBinaryTree(root,&BSTroot);
	cout<<BSTroot->data<<endl;
	return 1;
}*/