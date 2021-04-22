#ifndef BINARYSEARCHTREEAVL_H
#define BINARYSEARCHTREEAVL_H
#include "BinarySearchTree.h"

class BinarySearchTreeAVL:public BinarySearchTree{
	private:
		int treeHeight(node*);
		int heightDiff(node*);
		bool checkForUnbalance(node*);//idk
		void correct(node*);
		void leftRotation(node*);
		void rightRotation(node*);
	public:
		BinarySearchTreeAVL();
		~BinarySearchTreeAVL();
		void insert(char *);
		bool delete_(char *);
		//These two behave the same as in the regular tree, but with every
		//instance they check if the height balance is disturbed and act accordingly
};

#endif //BINARYSEARCHTREEAVL_H

//WIP
