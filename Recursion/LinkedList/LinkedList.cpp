#include<iostream>
#include "playing_with_cpp.h"
#include <stack>

using namespace std;

Node * addNode(Node *head, int value){
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data = value;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}
	else{
		Node *iter = head;
		while(iter->next){
			iter = iter->next;
		}
		iter->next = temp;
	}
	return head;
}

void printLinkedList(Node *head){
	while(head!=NULL){
		cout<<"\t"<<head->data;
		head = head->next;
	}
	cout<<endl;
}

// TODO :
Node * partitionAroundAValue(Node *head, int value){
	Node *greater = NULL, *greater_prev = NULL, *iter = head, *iter_prev = NULL;
	while(iter != NULL){
		if(iter->data > value){
			if(greater == NULL){
				greater = iter;
				greater_prev = iter_prev;
			}
			iter_prev = iter;
			iter = iter->next;
		}
		else{
			if(greater == NULL){
				iter_prev = iter;
				iter = iter->next;
			}
			else{
				iter_prev->next = iter->next;
				greater_prev->next = iter;
				iter->next = greater;
				greater_prev = greater_prev->next;
				iter = iter_prev->next;
			}
		}
	}
	return head;
}