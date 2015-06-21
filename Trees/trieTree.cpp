#include<iostream>

using namespace std;

#define SIZE 26

// Time : insertKey = O(key_length)
//        searchKey = O(key_length)

typedef struct trienode{
	int value;// leaf node will have value = word number
	struct trienode *child[SIZE];
}trieNode;

typedef struct trietree{
	int count;// the word count in the tree
	trieNode *root;
}trieTree;

trieNode * getNode(){
	trieNode * node = (trieNode *)malloc(sizeof(trieNode));
	node->value = 0;
	for(int i=0; i<SIZE; i++){
		node->child[i] = NULL;
	}
	return node;
}

void initializeTree(trieTree *trie){
	trie->count = 0;
	trie->root = getNode();
}

void insertKey(trieTree *trie, string key){
	// to check if key already present
	bool newKey = false;
	trieNode *node = trie->root;
	// traverse the tree to insert key
	for(int i=0; i<key.length(); i++){
		int index = (int)(key[i] - 'a');
		if(node->child[index] == NULL){ // key is a new key
			node->child[index] = getNode();
			newKey = true;
		}
		node = node->child[index];
	}
	if(newKey){
		trie->count++;
		// update the value of this last node to be word number
		node->value = trie->count;
	}
}

bool searchKey(trieTree *trie, string key){
	trieNode *node = trie->root;
	
	for(int i=0; i<key.length(); i++){
		int index = (int)(key[i] - 'a');
		if(node->child[index] == NULL){ // key is a new key
			return false;
		}
		node = node->child[index];
	}
	// check if this last node has non-positive value
	return node->value != 0 ? true : false;
}

bool isFreeNode(trieNode *node){
	for(int i=0; i<SIZE; i++){
		if(node->child[i] != 0){
			return false;
		}
	}
	return true;
}

bool deleteKeyHelper(trieNode *node, string key, int index){
	// Note: index=0 is the root node of trie, so key is from index=1 to key.length()
	if(node){
		// base case = when key is traversed till the end
		if(index == key.length()){
			if(node->value != 0){
				node->value = 0;
			}
			if(isFreeNode(node)){
				// mark node for deletion if its the last node of the key and has no children
				return true;
			}
			return false;
		}
		else{
			int which_child = (int)(key[index] - 'a');
			if(deleteKeyHelper(node->child[which_child],key,index+1)){
				// delete node->child[index]
				free(node->child[which_child]);
				node->child[which_child] = NULL;
				// mark node for deletion if not a leaf and has no children
				return (node->value == 0 && isFreeNode(node));
			}
		}
	}
	return false;
}

void deleteKey(trieTree *trie, string key){
	if(key.length() == 0){
		return;
	}
	trieNode *node = trie->root;
	bool ret = deleteKeyHelper(node,key,0);
}

/*
bool isStringConcatenationOfStringsInDictionary(string str, trieTree *trie){
	if(str.empty()){
		return true;
	}
	for(int i=0; i<str.length(); i++){
		
	}
}*/
/*
int main(){
	trieTree trie;
	initializeTree(&trie);
	insertKey(&trie,"the");
	insertKey(&trie,"them");
	insertKey(&trie,"theatre");
	insertKey(&trie,"toy");
	insertKey(&trie,"toss");
	insertKey(&trie,"hello");
	insertKey(&trie,"world");
	insertKey(&trie,"owl");
	insertKey(&trie,"worn");
	//cout<<isStringConcatenationOfStringsInDictionary("helloworld",&trie)<<endl;
	deleteKey(&trie,"the");

	cout<<"find key = "<<searchKey(&trie,"them")<<endl;
	cout<<"find key = "<<searchKey(&trie,"the")<<endl;
	return 1;
}*/