#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

void inorderTraversal(binaryNode *root, vector<binaryNode *> &arr){
	if(root){
		inorderTraversal(root->left,arr);
		arr.push_back(root);
		inorderTraversal(root->right,arr);
	}
}

void postorderTraversal(binaryNode *root, vector<binaryNode *> &arr){
	if(root){
		postorderTraversal(root->left,arr);
		postorderTraversal(root->right,arr);
		arr.push_back(root);
	}
}

binaryNode *findClosestAncestorByTraversal(binaryNode *root, binaryNode *p, binaryNode *q){
	vector<binaryNode *> inorder_arr;
	vector<binaryNode *> postorder_arr;
	inorderTraversal(root,inorder_arr);
	postorderTraversal(root,postorder_arr);
	map<binaryNode *,int> mp;
	int start,end;
	// locate p and q in inorder traversal
	for(int i=0; i<inorder_arr.size(); i++){
		if(inorder_arr[i]->data == p->data){
			start = i;
		}
		else if(inorder_arr[i]->data == q->data){
			end = i;
			break;
		}
	}
	// push the substring p to q into a map
	for(int i=start; i<=end; i++){
		mp[inorder_arr[i]] = 1;
	}
	// locate the substring in postorder traversal. Last node found is the ancestor.
	for(int i=0; i<postorder_arr.size(); i++){
		if(mp.find(postorder_arr[i]) != mp.end()){
			if(mp.size() == 1){
				return postorder_arr[i];
			}
			mp.erase(postorder_arr[i]);
		}
	}
	return NULL;
}