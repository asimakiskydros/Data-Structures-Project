#ifndef BINARYSEARCHTREEAVL_H
#define BINARYSEARCHTREEAVL_H
#include "BinarySearchTree.h"

class BinarySearchTreeAVL:public BinarySearchTree{
	private:
		int subRightTreeHeight, subLeftTreeHeight;
		void checkHeightDifference();
		void leftRotation();
		void rightRotation();
	public:
		void insert(char *);
		void delete_node(node *);
		//These two behave the same as in the regular tree, but with every
		//instance they check if the height balance is disturbed and act accordingly
};

//prosorina templates kai ta 2 logika tha allaksoun kapoia pragmata
//an exeis na prostheseis kati grapsto

#endif //BINARYSEARCHTREEAVL_H

//WIP
