#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

// Time : O(h)
binaryNode * inorderSuccessor(binaryNode *root, binaryNode *node){
	if(root == NULL || node == NULL){
		return NULL;
	}
	binaryNode *temp = NULL;
	if(node->right){
		// successor is the smallest element in the right subtree
		temp = node->right;
		while(temp->left){
			temp = temp->left;
		}
		return temp;
	}

	temp = root;
	// while node is not found
	while(root && root->data != node->data){
		if(node->data < root->data){
			temp = root;
			root = root->left;
		}
		else{
			root = root->right;
		}
	}
	return temp;
}
/*
int main(){
	binaryNode *root = getBinaryNode(10);
	root->left = getBinaryNode(5);
	root->left->left = getBinaryNode(2);
	root->left->right = getBinaryNode(7);
	root->right = getBinaryNode(15);
	root->right->left = getBinaryNode(11);
	binaryNode *successor = inorderSuccessor(root,root->left->right);
	cout<<successor->data<<endl;
	return 1;
}*/