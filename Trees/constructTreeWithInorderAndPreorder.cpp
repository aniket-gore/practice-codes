#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

BSTNode * constructTreeWithInorderAndPreorder(int inorder[], int preorder[], int instart, int inend){
	static int preindex = 0;
	if(instart > inend){
		return NULL;
	}

	BSTNode *newnode = (BSTNode *)malloc(sizeof(BSTNode));
	newnode->value = preorder[preindex];
	newnode->left = newnode->right = NULL;
	//when no children
	if(instart == inend){
		return newnode;
	}
	int i;
	//find where to partition inorder traversal
	for(i=instart; i<=inend; i++){
		if(inorder[i] == preorder[preindex])
			break;
	}
	preindex++;
	newnode->left = constructTreeWithInorderAndPreorder(inorder,preorder,instart,i-1);
	preindex++;
	newnode->right = constructTreeWithInorderAndPreorder(inorder,preorder,i+1,inend);
	return newnode;
}