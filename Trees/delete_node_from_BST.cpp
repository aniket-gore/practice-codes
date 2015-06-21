#include<iostream>

typedef struct node{
	int value;
	struct node *left;
	struct node *right;
}Node;

static void deleteNode(Node ** root,int value)
	{
		//find the node to be deleted - cur
		//Father of node to be deleted - fat

		Node * curr = *root;
		Node * fath = NULL;

		while(curr!=NULL)
		{
			if(curr->value==value)
				break;
			fath = curr;
			curr = curr->value>value? curr->left: curr->right;
		}
		if(curr == NULL)
		{
			return;
		}

		//now current points to node to be deleted
		//case1: current has no children
		//case2: current has 1 child(either left or right)
		//case3: current has 2 chidren
		
		//rp be the replace node
		//f be the father of replace node
		//case1 and case2

		Node * rp=NULL,* f = NULL;
		if(curr->left==NULL)
		{
			rp = curr->right;
		}
		else if(curr->right==NULL)
		{
			rp = curr->left;
		}
		//case 3: 2 children
		else
		{
			//find inorder successor of CURR as replacement node
			f=curr;
			rp=curr->right;
			while(rp->left!=NULL)
			{
				f=rp;
				rp=rp->left;
			}

			//rp points to inorder successor of curr
			//replace rp with its right child
			//rp being the inorder successor does not have a left child
			//replace curr with rp
			if(f!=curr)
			{
				f->left = rp->right;
				rp->right = curr->right;
			}
			rp->left = curr->left;

		}

		//if curr is root
		if(fath==NULL)
		{
			*root = rp;
		}
		else
		{
			(fath->left == curr) ? fath->left = rp : fath->right = rp;
		}
		delete curr;
		curr = NULL;

		
	}