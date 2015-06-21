#include<iostream>
#include<vector>
#include<queue>
#include "playing_with_cpp.h"

using namespace std;

heapAndBSTNode *getNode(pair<int,int> values){
	heapAndBSTNode *node = (heapAndBSTNode *)malloc(sizeof(heapAndBSTNode));
	node->heapValue = values.first;
	node->bstValue = values.second;
	node->left = node->right = NULL;
	return node;
}

void inOrderTraversal(heapAndBSTNode *root){
	if(root){
		inOrderTraversal(root->left);
		cout<<endl<<root->heapValue<<","<<root->bstValue;
		inOrderTraversal(root->right);
	}
}

heapAndBSTNode * maxHeapAndBSTInSameStructure(vector<pair<int,int>> pairs){
	int max = -1, max_index = -1, bst_root_value = -1;
	//find the max element in the existing pairs which will be the root in the BST
	if(pairs.size() == 0){
		return NULL;
	}
	for(int i=0; i<pairs.size(); i++){
		if(max < pairs[i].first){
			max = pairs[i].first;
			max_index = i;
			bst_root_value = pairs[i].second;
		}
	}
	heapAndBSTNode *root = getNode(pairs[max_index]);
	pairs.erase(pairs.begin() + max_index);
	//find out the left and right subtrees of root in the heap
	vector<pair<int,int>> left_subtree, right_subtree;
	for(int i=0; i<pairs.size(); i++){
		if(pairs[i].second <= bst_root_value){
			left_subtree.push_back(pairs[i]);
		}
		else{
			right_subtree.push_back(pairs[i]);
		}
	}
	root->left = maxHeapAndBSTInSameStructure(left_subtree);
	root->right = maxHeapAndBSTInSameStructure(right_subtree);
	return root;
}