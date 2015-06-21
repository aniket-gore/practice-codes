#ifndef TRINARY_TREE_H
#define TRINARY_TREE_H
#include<iostream>

using namespace std;

#define DEFAULT_VALUE -99999

class trinaryTree{
private:
	int data;
	trinaryTree *left;
	trinaryTree *right;
	trinaryTree *middle;

public:
	trinaryTree();
	trinaryTree(int data);
	static trinaryTree * insertNode(trinaryTree *root, trinaryTree *node);
	static bool deleteNode(trinaryTree **root, int data);
	static void inorderTraversal(trinaryTree *root);
};

#endif