#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct node{
	char *data;
	int instances;
	node *left,*right;
};

class BinarySearchTree{
	private:
		node *root;
		void insert(char*,node*);
		node *search(char*,node*);
	public:
		BinarySearchTree();
		BinarySearchTree(char*);//probably unimportant?
		~BinarySearchTree();
		virtual void insert(char *);
		node* search(char *);//Searches for string, if it exists
		//returns its address and prints its details, if not returns NULL
		void destroy();//Destroys the tree in its entirety from the top down
		virtual bool delete_node(node *);//Finds then deletes the specified node
		//then returns true - if it doesnt exist it returns false
		void preorder();
		void inorder();
		void postorder();
		void levelorder();
		void get_max();
		void get_min();
};

#endif //BINARYSEARCHTREE_H

//yo goga an ksexnaw kapoia sinartisi grapse se sxolia

//WIP
