#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void eachNodeIsSumOfLeftSubtree(binaryNode *root){
	if(root != NULL){
		eachNodeIsSumOfLeftSubtree(root->left);
		if(root->left){
			root->data += root->left->data;
		}
		eachNodeIsSumOfLeftSubtree(root->right);
	}
}