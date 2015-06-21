#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

/*
method 1: Time = O(m * n) where m = nodes in A, n = nodes in B
          Space = O(1)
		  For each node in preorder traversal, check if node is equal to root of A. If yes, then
		  find if those trees are identical.

method 2: Time = O(n)
          Space = O(n)
		  Find inorder and preorder traversals of both the trees.
		  If both traversals of A are substrings of traversals of B, then its A is a subtree.
*/

bool areIdentical(binaryNode *rootA, binaryNode *rootB){
	if(rootA == NULL && rootB == NULL){
		return true;
	}
	if(rootA == NULL || rootB == NULL){
		return false;
	}
	return rootA->data == rootB->data && areIdentical(rootA->left,rootB->left) && areIdentical(rootA->right, rootB->right);
}

// is tree A a subtree of tree B
bool isSubtree(binaryNode *rootA, binaryNode *rootB){
	if(rootA == NULL){
		return true;
	}
	if(rootB == NULL){
		return false;
	}
	if(areIdentical(rootA,rootB)){
		return true;
	}
	return (isSubtree(rootA,rootB->left) || isSubtree(rootA,rootB->right));
}