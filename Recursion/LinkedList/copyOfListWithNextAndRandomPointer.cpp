#include<iostream>
#include<map>

using namespace std;

typedef struct node{
	int data;
	struct node *next;
	struct node *random;
}NodeRand;

NodeRand * getNode(int data){
	NodeRand *node = (NodeRand *)malloc(sizeof(NodeRand));
	node->data = data;
	node->next = NULL;
	node->random = NULL;
	return node;
}

/*
Create copy of a linked list where each node has a next pointer and a random pointer
*/

NodeRand *deepCopy(NodeRand *head){
	if(head == NULL){
		return NULL;
	}
	map<NodeRand *,NodeRand *> mp;
	NodeRand *temp = head;
	// create a map with original node -> corresponding new node
	while(temp){
		mp.insert(make_pair(temp,getNode(temp->data)));
		temp = temp->next;
	}
	// set the next and random pointers
	temp = head;
	while(temp){
		mp[temp]->next = mp[temp->next];
		mp[temp]->random = mp[temp->random];
		temp = temp->next;
	}
	return mp[head];
}
/*
int main(){
	NodeRand *head = getNode(1);
	head->next = getNode(2);
	head->next->next = getNode(3);
	head->random = head->next->next;
	head->next->random = head->next;
	head->next->next->random = head;
	
	NodeRand * head1 = deepCopy(head);
	while(head1){
		if(head1->next){
			cout<<head1->data<<", next="<<head1->next->data<<", random="<<head1->random->data<<endl;
		}
		else{
			cout<<head1->data<<", next=NULL"<<", random="<<head1->random->data<<endl;
		}
		head1 = head1->next;
	}
	return 1;
}*/