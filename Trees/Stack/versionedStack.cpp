#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

#define SIZE 10

/*
Build a version stack with functions push, pop, and print stack of version.
E.g.
version 1 = push 1
version 2 = push 2
version 3 = push 3
version 4 = pop
version 5 = push 4
Stack at version 5 is 4,2,1.
*/

Node *v_stack[SIZE];
int version = 0;

void push(int value){
	Node *node = (Node *)malloc(sizeof(Node));
	node->data = value;
	node->next = v_stack[version];
	v_stack[++version] = node;
}

int pop(){
	Node *node = v_stack[version];
	if(node == NULL){
		cout<<"Underflow!"<<endl;
		return -1;
	}
	else{
		int value = node->data;
		// set the prev node at the top of stack
		node = node->next;
		v_stack[++version] = node;
		return value;
	}
}

void printVersion(int version_number){
	if(version_number <= 0 || version_number > version){
		cout<<"Invalid version number."<<endl;
	}
	else{
		Node *node = v_stack[version_number];
		cout<<"Stack : ";
		while(node != NULL){
			cout<<node->data<<endl;
			node = node->next;
		}
	}
}
/*
int main(){
	v_stack[0] = NULL;
	push(1);
	push(2);
	push(3);
	int v = pop();
	push(4);
	printVersion(4);
	cout<<endl;
	return 1;
}*/