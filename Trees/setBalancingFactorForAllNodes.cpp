#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

typedef struct binarynodebBF{
	int data;
	struct binarynodebBF *left;
	struct binarynodebBF *right;
	int bf;
}binaryNodeBF;

int setBalancingFactorForAllNodes(binaryNodeBF *root){
	if(root == NULL){
		return 1;
	}
	int left = setBalancingFactorForAllNodes(root->left);
	int right = setBalancingFactorForAllNodes(root->right);
	root->bf = abs(left-right);
	return (left > right) ? left + 1 : right + 1;
}