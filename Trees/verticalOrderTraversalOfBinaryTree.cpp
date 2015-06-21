#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)

/*
		  1
        /    \
       2      3
      / \    / \
     4   5  6   7
             \   \
              8   9 
               
			  
The output of print this tree vertically will be:
4
2
1 5 6
3 8
7
9

Implementation : Time = O(n), Space = O(n)
method : Preorder traversal and add nodes to appropriate level key in hashmap. Print levelwise.

method 2 (not done here): Time = O(m * n) where m = number of vertical levels. Space = O(1).
Preorder traversal to get minLevel and maxLevel. For each level, traverse the tree and print the nodes of that level.
*/

void verticalOrderTraversalOfBinaryTreeHelper(binaryNode *root, int &minLevel, int&maxLevel, int level, map<int,vector<binaryNode *>> &mp){
	if(root == NULL){
		return;
	}

	// if level present in map, add root to the vector, else, create a vector with root
	if(mp.find(level) != mp.end()){
		mp[level].push_back(root);
	}
	else{
		vector<binaryNode *> vec;
		vec.push_back(root);
		mp.insert(make_pair(level,vec));
	}
	// maintain min and max vertical levels
	minLevel = min(minLevel,level);
	maxLevel = max(maxLevel,level);

	verticalOrderTraversalOfBinaryTreeHelper(root->left,minLevel,maxLevel,level-1,mp);
	verticalOrderTraversalOfBinaryTreeHelper(root->right,minLevel,maxLevel,level+1,mp);
}

void verticalOrderTraversalOfBinaryTree(binaryNode *root){
	// map of level->nodes in level
	map<int,vector<binaryNode *>> mp;
	int minLevel = INT_MAX, maxLevel = INT_MIN;
	// get the min and max levels and nodes at each level
	verticalOrderTraversalOfBinaryTreeHelper(root,minLevel,maxLevel,0,mp);

	//print levelwise
	for(int i=minLevel; i<=maxLevel; i++){
		cout<<endl;
		for(int j=0; j<mp[i].size(); j++){
			cout<<mp[i][j]->data<<",";
		}
	}
}
/*
int main(){
	binaryNode *root = getBinaryNode(1);
	root->left = getBinaryNode(2);
	root->right = getBinaryNode(3);
	root->left->left = getBinaryNode(4);
	root->left->right = getBinaryNode(5);
	root->right->left = getBinaryNode(6);
	root->right->right = getBinaryNode(7);
	root->right->left->right = getBinaryNode(8);
	root->right->right->right = getBinaryNode(9);
	verticalOrderTraversalOfBinaryTree(root);
	return 1;
}*/