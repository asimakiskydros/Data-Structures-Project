#include <iostream>
#include <fstream>
#include "unsortedArray.h"
#include "sortedArray.h"
#include "BinarySearchTree.h"
#include "BinarySearchTreeAVL.h"
#include "mystring.h"
using namespace std;

int main() {
	ifstream ifs;
	ofstream ofs;
	mystring string;

	//NORMAL SEARCH TREE
	BinarySearchTree BT;
	ifs.open("test2.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			BT.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!)Reading file error"<<endl;
	ofs.open("test-output2.txt",ios::out | ios::app);
	if(ofs.is_open()){
		cout<<"File \"test-output.txt\" created successfully"<<endl;
		ofs<<"BINARY SEARCH TREE RESULTS:"<<endl;
		ofs<<"Searching for string \"the\""<<endl;
		if(!BT.search((char*)"the", ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Searching for string \"brown\""<<endl;	
		if(!BT.search((char*)"brown",ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"[]Pre-order:"<<endl;
		BT.preorder(ofs);
		ofs<<"[]In-order:"<<endl;
		BT.inorder(ofs);
		ofs<<"[]Post-order:"<<endl;
		BT.postorder(ofs);
		ofs<<"Attempting to delete string \"fox\""<<endl;
		if(BT.delete_((char*)"fox"))
			ofs<<">>Deletion successful"<<endl;
		else
			ofs<<"(!)Failed. Non-existant string or plausible error"<<endl;
		ofs<<"[]In-order (after deletion):"<<endl;
		BT.inorder(ofs);
		ofs<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!)Creating file error"<<endl;
	BT.reset();

	//AVL TREE
	BinarySearchTree BTAVL;
	ifs.open("test2.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			BTAVL.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!)Reading file error"<<endl;
	ofs.open("test-output2.txt",ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"BINARY SEARCH TREE AVL RESULTS:"<<endl;
		ofs<<"Searching for string \"the\""<<endl;
		if(!BTAVL.search((char*)"the", ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Searching for string \"brown\""<<endl;	
		if(!BTAVL.search((char*)"brown",ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"[]Pre-order:"<<endl;
		BTAVL.preorder(ofs);
		ofs<<"[]In-order:"<<endl;
		BTAVL.inorder(ofs);
		ofs<<"[]Post-order:"<<endl;
		BTAVL.postorder(ofs);
		ofs<<"Attempting to delete string \"fox\""<<endl;
		if(BTAVL.delete_((char*)"fox"))
			ofs<<">>Deletion successful"<<endl;
		else
			ofs<<"(!)Failed. Non-existant string or plausible error"<<endl;
		ofs<<"[]In-order (after deletion):"<<endl;
		BTAVL.inorder(ofs);
		ofs<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!)Editing file error"<<endl;
	BTAVL.reset();

	//UNSORTED ARRAY
	unsortedArray UARR;
	ifs.open("test2.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			UARR.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!)Reading file error"<<endl;
	ofs.open("test-output2.txt",ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"UNSORTED ARRAY RESULTS:"<<endl;
		ofs<<"Searching for string \"the\""<<endl;
		if(!UARR.search((char*)"the", ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Searching for string \"brown\""<<endl;	
		if(!UARR.search((char*)"brown",ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Attempting to delete string \"fox\""<<endl;
		if(UARR.delete_word((char*)"fox"))
			ofs<<">>Deletion successful"<<endl;
		else
			ofs<<"(!)Failed. Non-existant string or plausible error"<<endl;
		ofs<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!)Editing file error"<<endl;
	
	//SORTED ARRAY
	sortedArray SARR;
	ifs.open("test2.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			SARR.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!)Reading file error"<<endl;
	ofs.open("test-output2.txt",ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"SORTED ARRAY RESULTS:"<<endl;
		ofs<<"Searching for string \"the\""<<endl;
		if(!SARR.search((char*)"the", ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Searching for string \"brown\""<<endl;	
		if(!SARR.search((char*)"brown",ofs))
			ofs<<"(!)String could not be found"<<endl;
		ofs<<"Attempting to delete string \"fox\""<<endl;
		if(SARR.delete_word((char*)"fox"))
			ofs<<">>Deletion successful"<<endl;
		else
			ofs<<"(!)Failed. Non-existant string or plausible error"<<endl;
		ofs<<endl<<endl<<"<-----END-OF-FILE----->";
		ofs.close();
	}
	else
		cerr<<"(!)Editing file error"<<endl;
	
	return 0;
}
//profanws einai temporary template auto, den tha psaxnoume manually sto teliko version

//Kalo einai na mpoun me auksousa seira poliplokotitas, dld
// UARR->SARR->BT->BTAVL->HASHTBL
//to ekana etsi gia na swsw oso perissoteri mnimi mporw atm
//gi auto kalo einai na ulopoihseis ki esi reset() i delete() methodous

//a episis tha deis oti se merika simia kanw print kai stin othoni.
//kalitera min to kaneis auto, paizei na to afairesw gt tha ton ekneurizei an anoigei
//to cmd polles fores
