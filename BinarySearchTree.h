#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct node{
	char *data;
	int instances;
	node *left,*right;
};

class BinarySearchTree{
	protected:
		node *root;
		void insert(char*,node* /*root*/);
		node *search(char*,node* /*root*/,node* /*parent*/,bool* /*isRight?*/);
		void destroy(node* /*root*/);
		void print(node* /*root*/);
		void scan(node* /*root*/,short );//short: 1;preorder 2;inorder 3;postorder
	public:
		BinarySearchTree();//Creates empty tree
		~BinarySearchTree();
		virtual void insert(char *);
		node* search(char *);//Searches for string, if it exists
		//returns its address and prints its details, if not returns NULL
		void destroy();//Destroys the tree in its entirety from the bottom up
		virtual bool delete_(char *);//Finds then deletes the specified string
		//then returns true - if it doesnt exist it returns false
		void preorder();
		void inorder();
		void postorder();
		node* get_max();//Finds and prints the MAX value then returns its address
		node* get_min();//Works similarly, for the MIN value
};

#endif //BINARYSEARCHTREE_H
