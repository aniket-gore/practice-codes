#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

// Time : O(nlogn)
// Traverse to middle and recurse 1st and 2nd halves
BSTNode * sortedLinkedListToBST(Node *head, int length){
	if(length == 0){
		return NULL;
	}

	if(length == 1){
		BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
		root->value = head->data;
		root->left = root->right = NULL;
		return root;
	}

	Node *temp = NULL, *prev = NULL;
	int count = 0;
	int middle = length/2 + 1;

	while(++count <= middle){
		temp = count == 1 ? head : temp->next;
	}
	// temp is the middle node
	BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
	root->value = temp->data;
	root->left = root->right = NULL;

	Node *secondhalfhead = temp->next;
	root->left = sortedLinkedListToBST(head, length/2);
	root->right = sortedLinkedListToBST(secondhalfhead,length - length/2 - 1);
	return root;
}