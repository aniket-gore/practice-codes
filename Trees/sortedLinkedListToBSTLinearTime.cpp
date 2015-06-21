#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

// Time : O(n)
// pass pointer to pointer to head (IMPORTANT)
BSTNode * sortedLinkedListToBSTLinearTime(Node **head, int length){
	if(head == NULL || length == 0){
		return NULL;
	}
	BSTNode *left = sortedLinkedListToBSTLinearTime(head,length/2);

	BSTNode *root = (BSTNode *)malloc(sizeof(BSTNode));
	root->value = (*head)->data;
	root->left = left;

	(*head) = (*head)->next;
	root->right = sortedLinkedListToBSTLinearTime(head,length - length/2 - 1);

	return root;
}

BSTNode * sortedLinkedListToBSTLinearTimeCaller(Node *head){
	int length = 0;
	Node *temp = head;
	// find length of linked list
	while(temp){
		length++;
		temp = temp->next;
	}
	return sortedLinkedListToBSTLinearTime(&head,length);
}