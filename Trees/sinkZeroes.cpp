#include<iostream>
#include "playing_with_cpp.h"
#include<deque>

using namespace std;

/*
Sink Zeroes in Binary Tree. No node with value zero could be parent of node with non-zero.
*/

void sinkZeroes(binaryNode *root, deque<binaryNode *> &dq){
	if(root == NULL){
		return;
	}
	if(root->data == 0){
		dq.push_back(root);
	}
	else{
		if(!dq.empty()){
			swap(root->data,dq.front()->data);
			dq.pop_front();
			dq.push_back(root);
		}
	}
	
	sinkZeroes(root->left,dq);
	sinkZeroes(root->right,dq);
	
	if(!dq.empty() && dq.back() == root){// 0 is already at the leaf
		dq.pop_back();
	}
}
