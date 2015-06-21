#include<iostream>
#include "playing_with_cpp.h"

//Time = O(nlogn)

BSTNode * getNode(int data){
	BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
	node->value = data;
	node->left = node->right = NULL;
	return node;
}

BSTNode * preorderToBST(int *arr, int length){
	BSTNode *node = NULL;
	node = getNode(arr[0]);

	int i;
	// index i starts from &arr[] passed to the recursion
	for(i=1; i<length; i++){
		if(arr[0] < arr[i]){
			break;
		}
	}
	// if the length is 1, then node-left = node-right = NULL and node is returned
	node->left = (i > 1) ? preorderToBST(&arr[1],i-1) : NULL;
	node->right = (length > i) ? preorderToBST(&arr[i],length-i) : NULL;
	return node;
}
/*
int main(){
	int arr[] = {5,2,1,3,10,7,11};
	BSTNode *root = preorderToBST(arr,7);
	inOrderTraversal(root);
	return 1;
}*/