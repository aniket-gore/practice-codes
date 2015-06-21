#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

int maxSumPathBetweenTwoLeaves(binaryNode *root, int &globalmaxsum){
	if(root == NULL){
		return 0;
	}
	int lsubtreemaxsum = maxSumPathBetweenTwoLeaves(root->left,globalmaxsum);
	int rsubtreemaxsum = maxSumPathBetweenTwoLeaves(root->right,globalmaxsum);
	
	//max sum path passing through root
	int currentmaxsum = lsubtreemaxsum + rsubtreemaxsum + root->data;
	
	globalmaxsum = max(globalmaxsum,currentmaxsum);

	return (max(lsubtreemaxsum,rsubtreemaxsum) + root->data);
}