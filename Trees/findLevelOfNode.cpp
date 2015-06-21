#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

int findLevelOfNode(binaryNode *a, binaryNode *root, int level){
	if(root == NULL){
		return 0;
	}
	if(root == a){
		return level;
	}
	int l = findLevelOfNode(a,root->left,level+1);
	if(l != 0){
		return l;
	}
	return findLevelOfNode(a,root->right,level+1);
}