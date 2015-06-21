#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void morrisTraversal(binaryNode *root){
	if(root == NULL){
		return;
	}
	binaryNode *current = root;

	while(current != NULL){
		if(current->left == NULL){
			cout<<current->data<<",";
			current = current->right;
		}
		else{
			binaryNode *pre = current->left;
			while(pre->right != NULL && pre->right != current){
				pre = pre->right;
			}
			/* Make current as right child of its inorder predecessor */
			if(pre->right == NULL){
				pre->right = current;
				current = current->left;
			}
			/* Revert the changes made in if part to restore the original 
        tree i.e., fix the right child of predecssor */   
			else{
				cout<<current->data<<",";
				pre->right = NULL;
				current = current->right;
			}
		}
	}
}