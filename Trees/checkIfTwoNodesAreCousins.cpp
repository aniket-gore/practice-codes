#include<iostream>
#include"playing_with_cpp.h"

using namespace std;

bool checkIfTwoNodesAreCousins(binaryNode *a, binaryNode *b, binaryNode *root){
	if(root == NULL){
		return false;
	}
	return (findLevelOfNode(a,root,1) == findLevelOfNode(b,root,1) && !checkIfTwoNodesAreSiblings(a,b,root)) ? true : false;
}