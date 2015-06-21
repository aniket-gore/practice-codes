#include "trinaryTree.h"

/*
*	Function : trinaryTree()
*	Description : Default constructor
*/
trinaryTree::trinaryTree(){
	data = DEFAULT_VALUE;
	left = NULL;
	right = NULL;
	middle = NULL;
}

/*
*	Function : trinaryTree()
*	Description : Parameterized constructor
*/
trinaryTree::trinaryTree(int data){
	this->data = data;
	left = NULL;
	right = NULL;
	middle = NULL;
}

/*
*	Function : insertNode()
*	Description : Adds a node to the trinary tree
*	Arguments : root = pointer to root of the tree
*				newnode = pointer to a trinary node which is to be added
*	Returns :  pointer to root of the tree
*/
 trinaryTree * trinaryTree::insertNode(trinaryTree *root, trinaryTree *newnode){
	// If tree is empty, then assign newnode as the root
	if(root == NULL){
		root = newnode;
		return root;
	}
	trinaryTree *current = root, *previous = NULL;
	while(current){
		// If newnode data is equal to current data, then traverse the middle links and add it to the end
		if(newnode->data == current->data){
			while(current->middle){
				current = current->middle;
			}
			current->middle = newnode;
			return root;
		}
		// Else traverse the left or right subtree
		previous = current;
		if(newnode->data < current->data){
			current = current->left;
		}
		else if(newnode->data > current->data){
			current = current->right;
		}
	}
	// No data in tree matches the newnode data, so add the newnode to the appropriate link of the previous node
	if(newnode->data < previous->data){
		previous->left = newnode;
	}
	else{
		previous->right = newnode;
	}
	return root;
}

/*
*	Function : deleteNode()
*	Description : Deletes the specified node from the trinary tree
*	Arguments : root = pointer to pointer to root of the tree
*				data = data value of the node/nodes to be deleted
*	Returns : boolean value whether deletion is successful
*/
bool trinaryTree::deleteNode(trinaryTree **root, int data){
	trinaryTree *delete_node = *root, *parent = NULL;
	// Locate the node to be deleted in the tree
	while(delete_node){
		if(delete_node->data == data){
			break;
		}
		parent = delete_node;
		delete_node = (data < delete_node->data) ? delete_node->left : delete_node->right;
	}
	// NOTE : delete_node points to the node to be deleted
	// If node to be deleted is not found, return false
	if(delete_node == NULL){
		return false;
	}
	// Delete all the middle links of delete_node
	trinaryTree *temp = delete_node->middle;
	delete_node->middle = NULL;
	while(temp){
		trinaryTree *tempnext = temp->middle;
		delete(temp);
		temp = tempnext;
	}

	// Find the replacement node for delete_node
	trinaryTree *replacement_node, *parent_of_replacement_node;
	// Case 1 : delete_node has no left or right subtrees
	if(delete_node->left == NULL && delete_node->right == NULL ){
		replacement_node = NULL;
	}
	// Case 2 : delete_node has either left subtree or right subtree
	else if(delete_node->left == NULL){
		replacement_node = delete_node->right;
	}
	else if(delete_node->right == NULL){
		replacement_node = delete_node->left;
	}
	else{
		// Case 3 : delete_node has both left and right subtrees,
		// Find the inorder successor of delete_node.
		// replacement_node is the inorder successor, also keep track of parent of replacement_node
		parent_of_replacement_node = delete_node;
		replacement_node = delete_node->right;
		while(replacement_node->left){
			parent_of_replacement_node = replacement_node;
			replacement_node = replacement_node->left;
		}
		if(parent_of_replacement_node != delete_node){
			parent_of_replacement_node->left = replacement_node->right;
			replacement_node->right = delete_node->right;
		}
		replacement_node->left = delete_node->left;
	}
	// Replace the delete_node by the replacement node
	if(parent == NULL){
		*root = replacement_node;
	}
	else{
		if(parent->left == delete_node){
			parent->left = replacement_node;
		}
		else{
			parent->right = replacement_node;
		}
	}
	// Delete the node
	delete delete_node;
	delete_node = NULL;
	return true;
}


/*
*	Function : inorderTraversal()
*	Description : Traverse the in inorder manner
*	Arguments : node = pointer to a node from where to start traversal
*	Returns : NONE
*/
void trinaryTree::inorderTraversal(trinaryTree *node){
	if(node != NULL){
		inorderTraversal(node->left);		
		trinaryTree *node_middle = node;
		// Print all the middle links of the current node
		while(node_middle){
			cout<<node->data<<"\t";
			node_middle = node_middle->middle;
		}
		inorderTraversal(node->right);
	}
}

void testTri(){
	trinaryTree *root = NULL;
	root = trinaryTree::insertNode(root,new trinaryTree(4));
	root = trinaryTree::insertNode(root,new trinaryTree(2));
	root = trinaryTree::insertNode(root,new trinaryTree(1));
	root = trinaryTree::insertNode(root,new trinaryTree(6));
	root = trinaryTree::insertNode(root,new trinaryTree(5));
	root = trinaryTree::insertNode(root,new trinaryTree(4));
	root = trinaryTree::insertNode(root,new trinaryTree(7));
	trinaryTree::deleteNode(&root,4);
	trinaryTree::inorderTraversal(root);
}