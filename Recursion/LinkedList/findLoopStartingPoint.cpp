#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

int findLoopStartingPoint(Node *head){
	Node *slow = head, *fast = head;
	if(head == NULL){
		return -1;
	}
	if(!head->next || !head->next->next){
		return -1;
	}
	else{
		slow = head->next;
		fast = head->next->next;
	}
	while(fast != slow){
		slow = slow->next;
		if(!fast->next || !fast->next->next){
			return -1;
		}
		fast = fast->next->next;
	}
	slow = head;
	while(fast != slow){
		slow = slow->next;
		fast = fast->next;
	}
	return slow->data;
}