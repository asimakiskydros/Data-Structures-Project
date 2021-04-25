#include "BinarySearchTreeAVL.h"

BinarySearchTreeAVL::BinarySearchTreeAVL():BinarySearchTree(){}
BinarySearchTreeAVL::~BinarySearchTreeAVL(){
	destroy(root);
}
int BinarySearchTreeAVL::treeHeight(node *ptr){
	if(ptr==nullptr)
		return 0;
	if(ptr->left==nullptr && ptr->right==nullptr)
		return 1;
	int heightR=treeHeight(ptr->right);
	int heightL=treeHeight(ptr->left);
	return heightR>heightL ? 1+heightR : 1+heightL;
}
int BinarySearchTreeAVL::heightDiff(node* ptr){
	return treeHeight(ptr->left)-treeHeight(ptr->right);
}
void BinarySearchTreeAVL::insert(char *string){
	BinarySearchTree::insert(string,root);//add the string
	node *parent=nullptr;
	bool rightChild=0;
	node* pos=search(string,root,parent,&rightChild);//find the newly added node and its details
	scanForUnbalance(pos,parent,rightChild);//check if the tree it belongs is disturbed and act
	scanForUnbalance(root,nullptr,0);//scan the entire tree just in case a double rotation is needed
}
bool BinarySearchTreeAVL::delete_(char *string){
	node *parent=nullptr,*grandpa=nullptr;
	bool rightChild=0;
	search(string,root,parent,&rightChild);//find the parent and its details
	rightChild=0;
	search(parent->data,root,grandpa,&rightChild);//find the grandpa and its details
	bool response=BinarySearchTree::delete_(string);//remove the string
	if(response==true){
		scanForUnbalance(parent,grandpa,rightChild);//check if the parent tree is now disturbed and act
		scanForUnbalance(root,nullptr,0);//scan the entire tree just in case a double rotation is needed
	}
	return response;
}//this was done pretty fast, might be wrong
void BinarySearchTreeAVL::leftRotation(node *ptr,node *parent,bool isRight){
	node *temp=ptr->right;
	if(heightDiff(ptr->right)>0){//(Subtree ptr->right) heightL>heightR
		ptr->right=ptr->right->right;
		temp->right=ptr;
	}
	else{//(Subtree ptr->right) heightL<=heightR
		ptr->right=ptr->right->left;
		temp->left=ptr;
	}
	if(isRight==true)
			parent->right=temp;
		else
			parent->left=temp;
	//A left rotation is required when the right subtree of the original node is unbalanced
	//Simply find whichever subtree of the node->right tree is taller and make the other one the new right
	//child of the original node.
	//Then move the original node to the right node's child spot just left vacant.
	//Finally make the right child node the new head of the master tree. 
}
void BinarySearchTreeAVL::rightRotation(node *ptr,node *parent,bool isRight){
	node *temp=ptr->left;
	if(heightDiff(ptr->right)>0){//(Subtree ptr->right) heightL>heightR
		ptr->left=ptr->left->right;
		temp->right=ptr;
	}
	else{//(Subtree ptr->right) heightL<=heightR
		ptr->left=ptr->left->left;
		temp->left=ptr;
	}
	if(isRight==true)
			parent->right=temp;
		else
			parent->left=temp;
	//Exact same logic
}
bool BinarySearchTreeAVL::scanForUnbalance(node * ptr, node* parent,bool isRight){
	if(ptr==nullptr)//probably unimportant; it shouldn't safeguard from crashes if the pointer is non-existant
		return false;
	int HD=heightDiff(ptr);
	if(HD==0 || HD==1 || HD==-1)
		return false;
	if(HD<-1)//Unbalanced right subtree
		leftRotation(ptr,parent,isRight);
	else if(HD>1)//Unbalanced left subtree
		rightRotation(ptr,parent,isRight);
	return true;
}
//Implementation done - menei to bugfixing
