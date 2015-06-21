#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void removeNumberFromLinkedList(Node **head, int data){
	Node *temp = *head;

	// check if data present at the start
	while(temp && temp->data == data){
		temp = temp->next;
	}
	if(temp == NULL){
		*head = NULL;
		return;
	}
	else{
		*head = temp;
	}

	Node *prev = temp;
	while(temp->next != NULL){
		temp = temp->next;
		if(temp->data != data){
			prev->next = temp;
			prev = prev->next;
		}
	}
	prev->next = NULL;
}
/*
int main(){
	Node *head = NULL;
	head = addNode(head,3);
	head = addNode(head,2);
	head = addNode(head,2);
	head = addNode(head,2);
	head = addNode(head,2);
	head = addNode(head,3);
	removeNumberFromLinkedList(&head,3);
	printLinkedList(head);
	return 1;
}*/