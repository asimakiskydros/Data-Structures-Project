#include "BinarySearchTree.h"
#include <cstring>
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){
	root=nullptr;
}
BinarySearchTree::~BinarySearchTree(){
	destroy(root);
}
//Public part - the user can't be expected to provide a node
void BinarySearchTree::insert(char* string){
	node *tmp,*parent=nullptr;
	//if the tree is empty, place at root
	if(root==nullptr){
		insert(string,root);
		return;
	}
	else{
		tmp=search(string,root,parent);
		//Identical strings occupy the same node multiple times
		if(tmp!=nullptr)
			tmp->instances++;
		else{//If it's not where the function last checked, it should be placed there
			if(strcmp(string,parent->data)>0){
				parent->right=new node;
				parent->right->right=nullptr;
				parent->right->left=nullptr;
				insert(string,parent->right);
			}
			else if(strcmp(string,parent->data)<0){
				parent->left = new node;
				parent->left->right=nullptr;
				parent->left->left=nullptr;
				insert(string,parent->left);
			}
		}
	}
}
//Private part - the node is required
void BinarySearchTree::insert(char *string,node* ptr){
	//get string
	ptr->data=new char[strlen(string)+1];
	strcpy(ptr->data,string);
	ptr->data[strcspn(ptr->data," \n")]='\0';
	
	ptr->instances=1;	
}
//Public part - same reasoning as before
node *BinarySearchTree::search(char *string){
	int timecount;//unfinished
	node* ptr=search(string,root,nullptr);
	if(ptr==nullptr)
		return nullptr;
	else{
		cout<<"String \""<<string<<"\" exists in the binary tree "<<ptr->instances<<" time(s) (search time: "<<timecount<<" seconds)."<<endl;
	}
	return ptr;
}
//Private part
node *BinarySearchTree::search(char *string,node *ptr, node* parent){
	int comparator=strcmp(ptr->data,string);
	if(ptr->left==nullptr && ptr->right==nullptr){//end of the line  
		if(comparator!=0)//the string does not exist
			return nullptr;
		else//Found!
			return ptr;
	}
	else{ 
		if(ptr->right!=nullptr && comparator<0)//then string>node data
			return search(string,ptr->right,ptr);
		else if(ptr->left!=nullptr && comparator>0)//then string<node data
			return search(string,ptr->left,ptr);
	}
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
	if(ptr!=nullptr){
		delete ptr->data;
		delete ptr->left;
		delete ptr->right;
		delete ptr;
	}
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

//Oso perisotero ta koitaw toso pio poly moy fainetai oti einai ola lathos xddd
//papadopoule r mlk mas ponese to kefali 
