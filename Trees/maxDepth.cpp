#include <iostream>
#include <stdio.h>

using namespace std;

struct Node{
	int key;
	Node *left;
	Node *right;
	Node *parent;
};

struct Tree{
	Node *root;
};



void insert(Tree* T, int key){
	
	Node *data = new Node;
	data->key = key;
	data->left=NULL;
	data->right=NULL;
	data->parent=NULL;

	if(T->root==NULL){
		T->root=data;
		return;
	}

	Node *temp = T->root;
	Node *tempParent = NULL;
	while(temp!=NULL){
		tempParent = temp;
		if(key<temp->key)
			temp=temp->left;
		else
			temp=temp->right;
	}
	
	data->parent=tempParent;
	
	if(key<tempParent->key)
		tempParent->left=data;
	else
		tempParent->right=data;
} 

Node* smallest(Node *root){
	if(root->left==NULL){
		return root;
	}

	return smallest(root->left);
}

Node* largest(Node *root){
	if(root==NULL){
		return root->parent;
	}

	return smallest(root->right);
}

void Transplant(Tree *T, Node *u, Node *v){
	if(u->parent==NULL)
		T->root = v;
	else if(u==u->parent->left)
		u->parent->left=v;
	else
		u->parent->right=v;

	if(v!=NULL)
		v->parent=u->parent;
}

void deleteNode(Tree *T, int key){
	Node *root = T->root;
	Node *temp;

	if(root==NULL){
		printf("%s\n", "No such element exists");
	}

	while(root->key!=key){
		if(root->key>key)
			root=root->left;
		else
			root=root->right;
	}


	if(root->left==NULL){
		Transplant(T, root, root->right);
		delete root;
	}
	else if(root->right==NULL){
		Transplant(T, root, root->left);
		delete root;
	}
	else{
		Node* minNext = smallest(root->right);

		if(minNext->parent!=root){
			Transplant(T, minNext, minNext->right);
			minNext->right = root->right;
			minNext->right->parent=minNext;
		}

		Transplant(T, root, minNext);
		minNext->left = root->left;
		minNext->left->parent=minNext;

		if(minNext->parent==NULL)
			T->root=minNext;

		delete root;
	}
}

void printVal(Node *root){
	if(root!=NULL){
		printVal(root->left);
		printf(" val : %d,", root->key);
		printf(" right : %d," , root->right==NULL?-1:root->right->key);
		printf(" left : %d,", root->left==NULL?-1:root->left->key);
		printf(" parent : %d\n", root->parent==NULL?-1:root->parent->key);
		printVal(root->right);
	}
}

void printTree(Tree* T){
	printVal(T->root);
}

int max(int a, int b){
	return a>b?a:b;
}

int getHeight(Node *root){
	if(root==NULL){
		return 0;
	}
	return 1+max(getHeight(root->left),getHeight(root->right));
}
 
int main(int argc, char const *argv[])
{	
	Tree *T = new Tree;
	insert(T,16);
	insert(T,10);
	insert(T,17);
	insert(T,6);
	insert(T,11);
	insert(T,18);
	insert(T,4);
	insert(T,5);
	insert(T,13);
	insert(T,19);
	insert(T,2);
	insert(T,12);
	insert(T,14);
	insert(T,1);
	insert(T,3);
	insert(T,15);


	printf("%d\n",getHeight(T->root));

	return 0;
}