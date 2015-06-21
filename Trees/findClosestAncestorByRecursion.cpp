#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

binaryNode * findClosestAncestorByRecursion(binaryNode *root, binaryNode *p, binaryNode *q){
	if(root == NULL){
		return NULL;
	}
	if(!p && !q){
		return NULL;
	}
	if(root->left == p || root->left == q || root->right == p || root->right == q){
		return root;
	}
	binaryNode *l = findClosestAncestorByRecursion(root->left,p,q);
	binaryNode *r = findClosestAncestorByRecursion(root->right,p,q);
	if(l != NULL && r != NULL){
		return root;
	}
	else if(l != NULL){
		return l;
	}
	else if(r != NULL){
		return r;
	}
	return NULL;
}