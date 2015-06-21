#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void printPath(int *path, int len){
	for(int i=0; i<len; i++){
		cout<<path[i]<<",";
	}
	cout<<endl;
}

// Time : O(n)

void printAllPathsFromRootToLeaf(binaryNode *root, int *path, int len){
	if(root == NULL){
		return;
	}
	path[len] = root->data;
	len++;
	if(root->left == NULL && root->right == NULL){
		printPath(path,len);
		return;
	}
	printAllPathsFromRootToLeaf(root->left,path,len);
	printAllPathsFromRootToLeaf(root->right,path,len);
}
/*
int main(){
	binaryNode *root = getBinaryNode(1);
	root->left = getBinaryNode(2);
	root->right = getBinaryNode(3);
	root->left->left = getBinaryNode(4);
	root->left->right = getBinaryNode(5);
	root->right->right = getBinaryNode(7);
	
	int arr[6];
	printAllPathsFromRootToLeaf(root,arr,0);
	cout<<endl;
	return 1;	
}*/