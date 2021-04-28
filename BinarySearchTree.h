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
		void insert(char*,node*);
		node *search(char*,node*);
		void destroy(node*);
		void print(node*);
		void scan(node*,short);//short: 1;preorder 2;inorder 3;postorder
		node *parent(char*,node*, bool* /*isRight*/);
	public:
		BinarySearchTree();//Creates empty tree
		~BinarySearchTree();
		virtual void insert(char *);
		node* search(char *);//Searches for string, if it exists
		//returns its address and prints its details, if not returns NULL
		void reset();//Resets the tree to an empty one (deletes everything and sets root to NULL)
		virtual bool delete_(char *);//Finds then deletes the specified string
		//then returns true - if it doesnt exist it returns false
		void preorder();
		void inorder();
		void postorder();
		char* get_max();//Finds the MAX value then returns its address
		char* get_min();//The exact same thing but for the MIN value
};

#endif //BINARYSEARCHTREE_H
