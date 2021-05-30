#include "BinarySearchTreeAVL.h"

BinarySearchTreeAVL::BinarySearchTreeAVL():BinarySearchTree(){}
int BinarySearchTreeAVL::treeHeight(node *ptr){
	if(ptr==nullptr)
		return 0;
	if(ptr->left==nullptr && ptr->right==nullptr)
		return 1;
	int heightR=treeHeight(ptr->right);
	int heightL=treeHeight(ptr->left);
	//A tree's height is the height of its longer subtree +1 for the root itself
	//(Making it zero-based complicates the recursive returns for little benefit)
	return heightR>heightL ? 1+heightR : 1+heightL;
}
int BinarySearchTreeAVL::heightDiff(node* ptr){
	return treeHeight(ptr->left)-treeHeight(ptr->right);
}
void BinarySearchTreeAVL::leftRotation(node *ptr,node *prnt,bool isRight){
	//We forget rotations entirely; simply pick the MIN of the right subtree as the new root
	//This works because that specific node is the immediate next of the current root
	//and thus able to support all the subtrees without ruining the Search Structure
	node *MIN,*parentMIN;
	MIN=ptr->right;
	parentMIN=ptr;
	while(MIN->left!=nullptr){
		parentMIN=MIN;
		MIN=MIN->left;
	}
	if(ptr==root){//Necessary in order to avoid SegFault (prnt==nullptr)
		node *temp;
		temp=root;
		parentMIN->left=MIN->right;//Reminder that the MIN can at most have one (right) child
		root=MIN;
		root->left=temp;
		root->right=temp->right;
		temp->right=nullptr;
		return;
	}
	parentMIN->left=MIN->right;
	if(isRight)
		prnt->right=MIN;
	else
		prnt->left=MIN;
	MIN->left=ptr;
	MIN->right=ptr->right;
	ptr->right=nullptr;
}
void BinarySearchTreeAVL::rightRotation(node *ptr,node *prnt,bool isRight){
	//Similarly, we pick the MAX of the left subtree here
	node *MAX,*parentMAX;
	MAX=ptr->left;
	parentMAX=ptr;
	while(MAX->right!=nullptr){
		parentMAX=MAX;
		MAX=MAX->right;
	}
	if(ptr==root){
		node *temp;
		temp=root;
		parentMAX->right=MAX->left;//As per the definition of MAX, it can have at most one (left) child
		root=MAX;
		root->right=temp;
		root->left=temp->left;
		temp->left=nullptr;
		return;
	}
	parentMAX->right=MAX->left;
	if(isRight)
		prnt->right=MAX;
	else
		prnt->left=MAX;
	MAX->right=ptr;
	MAX->left=ptr->left;
	ptr->left=nullptr;
}
bool BinarySearchTreeAVL::scanForUnbalance(node * ptr, node* prnt,bool isRight){
	if(ptr==nullptr)//Safeguard for crashes; if the tree is empty it cannot be unbalanced
		return false;
	int HD=heightDiff(ptr);
	bool resp3=false;
	if(HD!=0 && HD!=1 && HD!=-1){
		if(HD<-1)//Unbalanced right subtree
			leftRotation(ptr,prnt,isRight);
		else if(HD>1)//Unbalanced left subtree
			rightRotation(ptr,prnt,isRight);
		resp3=true;
	}
	bool resp1=scanForUnbalance(ptr->left,ptr,false);
	bool resp2=scanForUnbalance(ptr->right,ptr,true);
	//Return true if at least one change was made
	return (resp1 || resp2 || resp3);
}
void BinarySearchTreeAVL::insert(char *string){
	BinarySearchTree::insert(string);//add string
	node* prnt=nullptr;
	bool isright=false;
	scanForUnbalance(root,prnt,isright);
}
bool BinarySearchTreeAVL::remove(char *string){
	bool response=BinarySearchTree::remove(string);//delete string
	if(response){
		node* prnt=nullptr;
		bool isright=false;
		scanForUnbalance(root,prnt,isright);
	}
	return response;
}
