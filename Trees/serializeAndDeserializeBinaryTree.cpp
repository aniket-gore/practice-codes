#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

#define SIZE 6

void serialize(binaryNode *root, vector<int> &arr){
	if(root == NULL){
		arr.push_back(-1);
		return;
	}
	arr.push_back(root->data);
	serialize(root->left,arr);
	serialize(root->right,arr);
}


binaryNode * deserialize(vector<int> &arr){
    static int index = 0;
    if(index == arr.size()){
        return NULL;
    }
    if(arr[index] == -1){
        return NULL;
    }

    binaryNode *node = (binaryNode *)malloc(sizeof(binaryNode));
    node->left = node->right = NULL;
    node->data = arr[index];

    ++index;
    node->left = deserialize(arr);
    ++index;
    node->right = deserialize(arr);
    return node;
}
/*
int main(){
	binaryNode *root = getBinaryNode(1);
	root->left = getBinaryNode(2);
	root->right = getBinaryNode(3);
	root->left->left = getBinaryNode(4);
	root->left->right = getBinaryNode(5);
	root->right->right = getBinaryNode(7);
	
    vector<int> arr;
	serialize(root,arr);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;

    binaryNode *des_root = deserialize(arr);
    inOrderTraversal(des_root);
	cout<<endl;
	return 1;	
}*/
