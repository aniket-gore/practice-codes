#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

#define min(a,b) (a<b ? a : b)
#define max(a,b) (a>b ? a : b)

/*
       1
    /     \
   2       3
  /  \    / \
 4    5  6   7
Top view of the above binary tree is
4 2 1 3 7

        1
      /   \
    2       3
      \ 
        4  
          \
            5
             \
               6
Top view of the above binary tree is
2 1 3 6
*/

// Time : O(n)
// Space : O(n)
// Method: Traverse level-order and maintain min_hd level and max_hd level seen. If popped node has level
// less than min_hd or greater than max_hd, then print it and update min_hd and max_hd. Due to level_order we will always
// encounter the top nodes first which have same horizontal level.

// This method does not print in the required order, but gives you all the visible nodes
void printNodesTopViewInBinaryTree(binaryNode *root){
	if(root == NULL){
		return;
	}
	queue<pair<int,binaryNode *>> level_queue;
	int min_hd = INT_MAX, max_hd = INT_MIN; // min and max horizontal differences

	level_queue.push(make_pair(0,root));

	while(!level_queue.empty()){
		pair<int,binaryNode *>pairNode = level_queue.front();
		level_queue.pop();

		// print node if its height difference has been seen for the first time
		if(pairNode.first < min_hd || pairNode.first > max_hd){
			cout<<pairNode.second->data<<",";
		}
		// update min and max height differences seen
		min_hd = min(min_hd,pairNode.first);
		max_hd = max(max_hd,pairNode.first);

		if(pairNode.second->left){
			level_queue.push(make_pair(pairNode.first-1,pairNode.second->left));
		}
		if(pairNode.second->right){
			level_queue.push(make_pair(pairNode.first+1,pairNode.second->right));
		}
	}
}
/*
int main(){
	binaryNode *root = getBinaryNode(1);
	root->left = getBinaryNode(2);
	root->right = getBinaryNode(3);
	root->left->right = getBinaryNode(5);
	root->left->right->right = getBinaryNode(6);
	root->left->right->right->right = getBinaryNode(7);

	printNodesTopViewInBinaryTree(root);
	return 1;
}*/
