#include "BinarySearchTree.h"
#include <cstring>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){root=nullptr;}
BinarySearchTree::BinarySearchTree(char *string){
	root->data=new char[strlen(string)+1];
	strcpy(root->data,string);
	root->left=nullptr;
	root->right=nullptr;
	root->instances=1;
}
BinarySearchTree::~BinarySearchTree(){destroy();}
//Public part - the user shouldn't have to provide a node
void BinarySearchTree::insert(char* string){
	//if the tree is empty, place at root
	if(root==nullptr){
		insert(string,root);
		return;
	}
	//Identical strings occupy the same node multiple times
	else if(root!=nullptr && strcmp(root->data,string)==0){
		root->instances++;
		return;
	}
	if(strcmp(root->data,string)<0)//if new node>root
		insert(string,root->right);
	else if(strcmp(root->data,string)>0)//if new node<root
		insert(string,root->left);
}
//Private part - the node is required for the recursive method
//Basically, the algorithm deals with every node as if its the root of an empty (sub)tree
void BinarySearchTree::insert(char *string,node* ptr){
	ptr=new node;
	ptr->left=nullptr;
	ptr->right=nullptr;
	
	//get string
	ptr->data=new char[strlen(string)+1];
	strcpy(ptr->data,string);
	ptr->data[strcspn(ptr->data," \n")]='\0';
	
	ptr->instances=1;	
}
//Public part - same reasoning as before
node *BinarySearchTree::search(char *string){
	int timecount;//unfinished
	node* ptr=search(string,root);
	if(ptr==nullptr)
		return nullptr;
	else{
		cout<<"String "<<string<<" exists in the binary tree "<<ptr->instances<<" time(s) (search time: "<<timecount<<" seconds)."<<endl;
	}
	return ptr;
}
//Private part
node *BinarySearchTree::search(char *string,node *ptr){
	if(ptr->left==nullptr && ptr->right==nullptr && strcmp(ptr->data,string)!=0)
		//end of the line; the string does not exist
		return nullptr;
	int comparator=strcmp(ptr->data,string);
	if(comparator==0)//Found!
		return ptr;
	else if(comparator<0)//then string>node data
		return search(string,ptr->right);
	else//then string<node data
		return search(string,ptr->left);
}

//WIP
