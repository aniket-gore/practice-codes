#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

/*
To flatten a binary tree, according to the given example, is to recursively insert the left subtree to the right subtree
and append the original right subtree to the end of the left subtree, i.e
     root                        root
     /  \            ->            \
  left  right                      left
                                     \
                                    right
*/

// Recursion
// Output = the final returned root node is not the root of the tree. Initial root is the root.
binaryNode * binaryTreeToRightSkewedLinkedList(binaryNode *root){
	if(root == NULL){
		return NULL;
	}
	binaryNode *temp = root->right;
	if(root->left){
		root->right = root->left;
		root->left = NULL;
		root = binaryTreeToRightSkewedLinkedList(root->right);
	}
	if(temp){
		root->right = temp;
		root = binaryTreeToRightSkewedLinkedList(root->right);
	}
	return root;
}

// Iterative and no stack
/*
Each time when we prune a right subtree, 
we use while-loop to find the right-most leaf of the current left subtree, and append the subtree there.
*/
binaryNode * binaryTreeToRightSkewedLinkedListIterative(binaryNode *root){
	if(root == NULL){
		return NULL;
	}
	binaryNode *curr = root;
	while(curr){
		if(curr->left != NULL){
			if(curr->right != NULL){
				binaryNode *next = curr->left;
				while(next->right != NULL){
					next = next->right;
				}
				next->right = curr->right;
			}
			curr->right = curr->left;
			curr->left = NULL;
		}
		curr = curr->right;
	}
	return root;
}