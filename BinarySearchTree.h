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
		void destroy(node*);
	public:
		BinarySearchTree();//Creates empty tree
		BinarySearchTree(char*);//Creates tree with only one component, the given string
		//(probably unimportant for the purposes of this project)
		~BinarySearchTree();
		virtual void insert(char *);
		node* search(char *);//Searches for string, if it exists
		//returns its address and prints its details, if not returns NULL
		void destroy();//Destroys the tree in its entirety from the bottom up
		virtual bool delete_node(node *);//Finds then deletes the specified node
		//then returns true - if it doesnt exist it returns false
		void preorder();
		void inorder();
		void postorder();
		void levelorder();
		node* get_max();//Finds and prints the MAX value then returns its adress
		node* get_min();//Works accordingly, for the MIN value
};

#endif //BINARYSEARCHTREE_H

//yo goga an ksexnaw kapoia sinartisi grapse se sxolia

//WIP
