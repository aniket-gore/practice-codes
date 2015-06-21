#include<iostream>
#include "playing_with_cpp.h"

#define max(a,b) (a>b ? a : b)

using namespace std;

int longestPathBetween2Nodes(binaryNode *root, int &maxpath){
	if(root == NULL){
		return 0;
	}
	int l = longestPathBetween2Nodes(root->left,maxpath);
	int r = longestPathBetween2Nodes(root->right,maxpath);
	maxpath = max(maxpath,l+r+1);
	return max(l,r) + 1;
}