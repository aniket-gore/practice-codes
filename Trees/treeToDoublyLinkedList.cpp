#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

/*
Rephrase: BST to sorted linked list.
*/

void treeToDoublyLinkedList(binaryNode *root, binaryNode **head){
	static binaryNode *prev = NULL;
	if(root == NULL){
		return;
	}
	treeToDoublyLinkedList(root->left,head);

	if(prev == NULL){
		*head = root;
	}
	else{
		root->left = prev;
		prev->right = root;
	}
	prev = root;

	treeToDoublyLinkedList(root->right, head);
}
/*
int main(){
	binaryNode *root = getBinaryNode(10);
	root->left = getBinaryNode(5);
	root->left->left = getBinaryNode(2);
	root->left->right = getBinaryNode(7);
	root->right = getBinaryNode(15);
	root->right->left = getBinaryNode(11);
	binaryNode *head = NULL;
	treeToDoublyLinkedList(root,&head);
	
	binaryNode *temp = head;
	while(temp != NULL){
		cout<<temp->data<<", ";
		temp = temp->right;
	}
	cout<<endl;
	return 1;
}*/