#include<iostream>

using namespace std;

/*
Given a circular single linked list.Write a program that deletes every kth node until only one node is left. 
After kth node is deleted, start the procedure from (k+1)th node. 
e.g.list is 1->2->3->4->5->1 
k=3 
1. You are at 1, delete 3. 
List is: 1->2->4->5->1 
2. You are at 4, delete 1 
List is: 2->4->5->2 
3. You are at 2,delete 5 
List is: 2->4->2 
4. You are at 2, delete 2 
List is: 4 
Return 4. 
*/

typedef struct circularnode{
	int value;
	struct circularnode *next;
}circularNode;

circularNode *getNode(int value){
	circularNode *node = (circularNode *)malloc(sizeof(circularNode));
	node->value = value;
	node->next = node;
	return node;
}

void deleteNode(circularNode *curr, circularNode *prev){
	prev->next = curr->next;
	curr->next = NULL;
	free(curr);
}

circularNode * createCircularLL(circularNode *head, int length){
	if(length == 0){
		return NULL;
	}

	int val = 0;
	circularNode *node, *ptr;
	while(++val <= length){
		if(head == NULL){
			head = getNode(val);
			ptr = head;
		}
		else{
			node = getNode(val);
			node->next = ptr->next;
			ptr->next = node;
			ptr = node;
		}
	}
	return head;
}

void printCircularLL(circularNode *head){
	if(head == NULL){
		return;
	}
	cout<<endl;
	circularNode *tmp = head;
	cout<<tmp->value<<"\t";
	tmp = tmp->next;
	while(tmp != head){
		cout<<tmp->value<<"\t";	
		tmp = tmp->next;
	}
	cout<<endl;
}

circularNode * deleteEveryKthElementInCircularLL(circularNode *head, int k){
	if(head == NULL || head->next == head){
		return head;
	}
	circularNode *curr = head, *prev = head;
	while(prev->next != curr){
		prev = prev->next;
	}
	while(curr != curr->next){
		for(int i=1; i<k; i++){
			prev = curr;
			curr = curr->next;
		}
		deleteNode(curr,prev);
		curr = prev->next;
	}
	return curr;
}
/*
int main(){
	circularNode *head = createCircularLL(NULL,5);
	printCircularLL(head);
	head = deleteEveryKthElementInCircularLL(head,1);
	printCircularLL(head);
	return 1;
}*/