#include "BinarySearchTree.h"
#include <cstring>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
	root=nullptr;
}
BinarySearchTree::BinarySearchTree(char *string){
	root->data=new char[strlen(string)+1];
	strcpy(root->data,string);
	root->left=nullptr;
	root->right=nullptr;
	root->instances=1;
}
BinarySearchTree::~BinarySearchTree(){
	destroy(root);
}
//Public part - the user can't be expected to provide a node
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
	if(strcmp(root->data,string)<0)//then new node>root
		insert(string,root->right);
	else if(strcmp(root->data,string)>0)//then new node<root
		insert(string,root->left);
}
//Private part - the node is required for the recursive method
void BinarySearchTree::insert(char *string,node* ptr){
	//Basically, the algorithm deals with every node as if its the root of an empty (sub)tree
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
		cout<<"String \""<<string<<"\" exists in the binary tree "<<ptr->instances<<" time(s) (search time: "<<timecount<<" seconds)."<<endl;
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
//Public Part
void BinarySearchTree::destroy(){
	destroy(root);
}
//Private part
void BinarySearchTree::destroy(node *ptr){
	//Search and Destroy; From the bottom up, if it's not null, it's dead :)
	if(ptr->left!=nullptr)
		destroy(ptr->left);
	if(ptr->right!=nullptr)
		destroy(ptr->right);
	if(ptr!=nullptr)
		delete ptr;
}
node *BinarySearchTree::get_max(){
	//As this is a binary Search tree, the maximum value is the furthermost leaf on the right
	node *temp;
	temp=root;
	while(temp->right!=nullptr)
		temp=temp->right;
	cout<<"The maximum (or greatest) string in this tree is "<<temp->data<<endl;
	return temp;
}
node *BinarySearchTree::get_min(){
	//As expected, the furthermost leaf on the left is the minimum value
	node *temp;
	temp=root;
	while(temp->left!=nullptr)
		temp=temp->left;
	cout<<"The minimum (or lesser) string in this tree is "<<temp->data<<endl;
	return temp;
}
//WIP
