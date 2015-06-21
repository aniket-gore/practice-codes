#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

// Time = O(n)
// Space = stack size i.e. O(n)

bool isBSTUtil(binaryNode *root, int min, int max){
	if(root == NULL){
		return true;
	}
	if(root->data < min || root->data > max){
		return false;
	}
	// +1,-1 to allow only distinct values
	return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);
}

bool isBST(binaryNode *root){
	return isBSTUtil(root,INT_MIN,INT_MAX);
}

/*
int main(){
	binaryNode *root = getBinaryNode(10);
	root->left = getBinaryNode(5);
	root->left->left = getBinaryNode(2);
	root->left->right = getBinaryNode(7);
	root->right = getBinaryNode(15);
	root->right->left = getBinaryNode(11);
	cout<<"isBST = "<<isBST(root)<<endl;
	return 1;
}*/