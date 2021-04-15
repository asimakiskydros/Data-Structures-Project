#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

struct node{
	char *data;
	node *left,*right;
};

class BinarySearchTree{
	private:
		node *root;
	public:
		BinarySearchTree();
		BinarySearchTree(char*);
		~BinarySearchTree();
		virtual void insert(char *);
		node* search(char *);//Searches for string, if it exists
		//returns its address if not returns NULL (Probably, i might change it)
		void destroy();//Destroys the tree in its entirety from the top down
		virtual void delete_node(node *);//Finds then deletes the specified node
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
