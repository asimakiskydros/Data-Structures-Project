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
	BinarySearchTree::insert(string,root);
	int hd=heightDiff(root);
	if(hd!=1 && hd!=-1 && hd!=0)
		correct(root);
}
bool BinarySearchTreeAVL::delete_(char *string){
	bool response=BinarySearchTree::delete_(string);
	if(response==true){
		int hd=heightDiff(root);
		if(hd!=1 && hd!=-1 && hd!=0)
			correct(root);
	}
	return response;
}//OK, probably just checking the root for unbalance is way too optimistic
//i'll look into that
