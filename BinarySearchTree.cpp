#include "BinarySearchTree.h"
#include <cstring>
#include <iostream>
#include <chrono>
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
		bool boole=false;//unimportant here; only needed so the function works
		tmp=search(string,root,parent,&boole);
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
	bool boole=false;//unimportant here; only needed so the function works
	auto start= std::chrono::high_resolution_clock::now();
	node* ptr=search(string,root,nullptr,&boole);
	auto stop= std::chrono::high_resolution_clock::now();
	if(ptr==nullptr)
		return nullptr;
	else{
		auto duration=std::chrono::duration_cast<std::chrono::seconds>(stop-start);
		cout<<"String \""<<string<<"\" exists in the binary tree "<<ptr->instances<<" time(s) (search time: "<<duration.count()<<" seconds)."<<endl;
	}
	return ptr;
}
//Private part
node *BinarySearchTree::search(char *string,node *ptr, node* parent,bool* isRight){
	int comparator=strcmp(ptr->data,string);
	if(ptr->left==nullptr && ptr->right==nullptr){//end of the line  
		if(comparator!=0)//the string does not exist
			return nullptr;
		else//Found!
			return ptr;
	}
	else{
		parent=ptr; 
		if(ptr->right!=nullptr && comparator<0){//then string>node data
			*isRight=true;
			return search(string,ptr->right,parent,isRight);
		}
		else if(ptr->left!=nullptr && comparator>0){//then string<node data
			*isRight=false;
			return search(string,ptr->left,parent,isRight);
		}
	}
	return nullptr;//Only to avoid any warnings in compilation - it shouldn't be reachable
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
bool BinarySearchTree::delete_(char *string){
	node *toBeDeleted, *parent=nullptr;
	bool isRightChild=false;
	toBeDeleted=search(string,root,parent,&isRightChild);
	if(toBeDeleted==nullptr)//The string doesn't exist inside the tree
		return false;
	else if(toBeDeleted->instances>1)
		toBeDeleted->instances--;
	else if(toBeDeleted->instances==1){
		if(toBeDeleted->left==nullptr && toBeDeleted->right==nullptr){//First case: leaf
			delete toBeDeleted->data;
			delete toBeDeleted->left;
			delete toBeDeleted->right;
			if(isRightChild==true)
				parent->right=nullptr;
			else
				parent->left=nullptr;
			toBeDeleted=nullptr;
			delete toBeDeleted;
		}
		else if(toBeDeleted->right!=nullptr && toBeDeleted->left==nullptr){//Second case: Single child (right)
			if(isRightChild==true)//ie if the "toBeDeleted" node is the right child of the parent
				parent->right=toBeDeleted->right;
			else
				parent->left=toBeDeleted->right;
			delete toBeDeleted->data;
			delete toBeDeleted->left;
			toBeDeleted->right=nullptr;
			delete toBeDeleted->right;
			delete toBeDeleted;
		}
		else if(toBeDeleted->right==nullptr && toBeDeleted->left!=nullptr){//Second case: Single child (left)
			if(isRightChild==true)
				parent->right=toBeDeleted->left;
			else
				parent->left=toBeDeleted->left;
			delete toBeDeleted->data;
			delete toBeDeleted->right;
			toBeDeleted->left=nullptr;
			delete toBeDeleted->left;
			delete toBeDeleted;
		}
		else{//Third case: two children
			//Next in line to occupy the to-be-deleted node is its immediate next in ascending order
			//ie the MIN of its right subtree
			node *MIN=toBeDeleted->right,*parentMIN=toBeDeleted;
			while(MIN->left!=nullptr){
				parentMIN=MIN;
				MIN=MIN->left;
			}
			//Note: The MIN, by definition, can have at most one child, strictly the right one
			parentMIN->left=MIN->right;//if there is none it will default to nullptr
			if(isRightChild==true)
				parent->right=MIN;
			else
				parent->left=MIN;
			MIN->right=toBeDeleted->right;
			MIN->left=toBeDeleted->left;
			delete toBeDeleted->data;
			toBeDeleted->right=nullptr;
			toBeDeleted->left=nullptr;
			delete toBeDeleted->right;
			delete toBeDeleted->left;
			delete toBeDeleted;
			MIN=nullptr;
			parentMIN=nullptr;
			delete MIN;
			delete parentMIN;
		}
	}
	parent=nullptr;
	delete parent;
	return true;
}//paizei na einai oli lathos tha diksei sto bugfixing
void BinarySearchTree::print(node* ptr){
	cout<<ptr->data<<" (appears "<<ptr->instances<<" time(s)), ";
}
void BinarySearchTree::scan(node* ptr,short which){
	if(ptr==nullptr)
		return;
	if(which==1){//preorder; Root->Left->Right
		print(ptr);
		scan(ptr->left,1);
		scan(ptr->right,1);
	}
	else if(which==2){//inorder; Left->Root->Right
		scan(ptr->left,2);
		print(ptr);
		scan(ptr->right,2);
	}
	else if(which==3){//postorder; Left->Right->Root
		scan(ptr->left,3);
		scan(ptr->right,3);
		print(ptr);
	}
}
void BinarySearchTree::preorder(){
	scan(root,1);
}
void BinarySearchTree::inorder(){
	scan(root,2);
}
void BinarySearchTree::postorder(){
	scan(root,3);
}
//Done me to implementation - menei to bugfixing
