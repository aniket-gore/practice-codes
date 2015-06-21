#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void deepestNodesInBinaryTree(binaryNode *root, int level, int &maxlevel, vector<binaryNode *> &nodes){
	if(root == NULL){
		return;
	}
	if(maxlevel < level){
		nodes.clear();
		maxlevel = level;
		nodes.push_back(root);
	}
	else if(maxlevel == level){
		nodes.push_back(root);
	}
	deepestNodesInBinaryTree(root->left,level+1,maxlevel,nodes);
	deepestNodesInBinaryTree(root->right,level+1,maxlevel,nodes);
}
