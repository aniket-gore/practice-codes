#include<iostream>
#include "playing_with_cpp.h"

#define max(a,b) (a>b ? a : b)

using namespace std;

//Time = O(n)
void findMaxSumFromRootToLeaf(binaryNode *root, int current_sum, int &global_max){
	if(root == NULL){
		global_max = max(current_sum,global_max);
		return;
	}

	current_sum += root->data;
	findMaxSumFromRootToLeaf(root->left,current_sum,global_max);
	findMaxSumFromRootToLeaf(root->right,current_sum,global_max);
}
/*
int main(){
	binaryNode *root = getBinaryNode(10);
	root->left = getBinaryNode(5);
	root->left->left = getBinaryNode(2);
	root->left->right = getBinaryNode(7);
	root->right = getBinaryNode(1);
	root->right->left = getBinaryNode(2);
	int max = 0;
	findMaxSumFromRootToLeaf(root,0,max);
	cout<<"max sum = "<<max<<endl;
	return 1;
}*/