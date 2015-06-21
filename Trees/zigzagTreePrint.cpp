#include<iostream>
#include "playing_with_cpp.h"

using namespace std;

void zigzagTreePrint(binaryNode *root){
	if(root == NULL){
		return;
	}
	stack<binaryNode *> LtoR, RtoL;
	bool flag = 0;
	LtoR.push(root);

	while(!LtoR.empty() || !RtoL.empty()){
		if(flag == 0){
			while(!LtoR.empty()){
				binarynode *temp = LtoR.top();
				cout<<temp->data<<",";
				LtoR.pop();
				if(temp->right){
					RtoL.push(temp->right);
				}
				if(temp->left){
					RtoL.push(temp->left);
				}
			}
			flag = 1;
		}
		else if(flag == 1){
			while(!RtoL.empty()){
				binarynode *temp = RtoL.top();
				cout<<temp->data<<",";
				RtoL.pop();
				if(temp->left){
					LtoR.push(temp->left);
				}
				if(temp->right){
					LtoR.push(temp->right);
				}
			}
			flag = 0;
		}
	}
}
