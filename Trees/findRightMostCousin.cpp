#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

void findRightmostCousin(binaryNode *root, binaryNode *nodeA){
	if(root == NULL){
		return;
	}
	queue<binaryNode *> levelqueue;
	levelqueue.push(root);
	int count = 1;

	while(!levelqueue.empty()){
		binaryNode *cousin = NULL;
		count--;
		binaryNode *curr = levelqueue.front();
		levelqueue.pop();
		if(curr == nodeA){
			while(!levelqueue.empty()){
				cousin = levelqueue.front();
				levelqueue.pop();
			}
			cout<<endl<<"rightmost cousin = "<<cousin->data<<endl;
			return;
		}
		if(curr->left){
			levelqueue.push(curr->left);
		}
		if(curr->right){
			levelqueue.push(curr->right);
		}
		if(count == 0){
			count = levelqueue.size();
		}
	}
}