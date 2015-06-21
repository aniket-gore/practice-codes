#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

bool checkIfTwoNodesAreSiblings(binaryNode *a, binaryNode *b, binaryNode *root){
	if(root == NULL){
		return false;
	}
	return ((root->left == a && root->right == b) ||
			(root->left == b && root->right == a) ||
			checkIfTwoNodesAreSiblings(a,b,root->left) ||
			checkIfTwoNodesAreSiblings(a,b,root->right));
}