#include <iostream>
#include <fstream>
#include <chrono>
#include "unsortedArray.h"
#include "sortedArray.h"
#include "BinarySearchTree.h"
#include "BinarySearchTreeAVL.h"
#include "mystring.h"
#define CEILING 1000

using namespace std;
using namespace std::chrono;

int main(){
	ifstream ifs;
	ofstream ofs;
	mystring string;
	mystring Q[CEILING];

	//Get 1000 sample-words from document
	ifs.open("input.txt");
	if(ifs.is_open()){
		int count=0;
		while(ifs>>string && count<CEILING){
			string.fix();
			Q[count]=string;
		}
		ifs.close();
	}
	else{
		cerr<<"(!) Failed to get a word sample. Shutting down..."<<endl;
		exit(1);
	}

	//Unsorted Array
	unsortedArray UARR;
	ifs.open("input.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			UARR.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!) Reading file error trying to initialize unsorted array."<<endl;
	ofs.open("output.txt", ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"UNSORTED ARRAY RESULTS:"<<endl;
		auto t0=high_resolution_clock::now();
		for(int indx=0;indx<CEILING;indx++)
			if(!UARR.search(Q[indx].getData(),ofs))
				ofs<<"\""<<Q[indx].getData()<<"\" not found"<<endl;
		auto t1=high_resolution_clock::now();
		duration<double,milli> dt1 = t1-t0;
		ofs<<"Elapsed time: "<<fixed<<dt1.count()<<" msec"<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!) Exiting file error in unsorted array."<<endl;
	UARR.reset();

	//Sorted Array
	sortedArray SARR;
	ifs.open("input.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			SARR.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!) Reading file error trying to initialize sorted array."<<endl;
	ofs.open("output.txt", ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"SORTED ARRAY RESULTS:"<<endl;
		auto t2=high_resolution_clock::now();
		for(int indx=0;indx<CEILING;indx++)
			if(!SARR.search(Q[indx].getData(),ofs))
				ofs<<"\""<<Q[indx].getData()<<"\" not found"<<endl;
		auto t3=high_resolution_clock::now();
		duration<double,milli> dt2 = t3-t2;
		ofs<<"Elapsed time: "<<fixed<<dt2.count()<<" msec"<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!) Exiting file error in sorted array."<<endl;
	SARR.reset();

	//Binary Search Tree
	BinarySearchTree BST;
	ifs.open("input.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			BST.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!) Reading file error trying to initialize binary search tree."<<endl;
	ofs.open("output.txt", ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"BINARY SEARCH TREE RESULTS:"<<endl;
		auto t4=high_resolution_clock::now();
		for(int indx=0;indx<CEILING;indx++)
			if(!BST.search(Q[indx].getData(),ofs))
				ofs<<"\""<<Q[indx].getData()<<"\" not found"<<endl;
		auto t5=high_resolution_clock::now();
		duration<double,milli> dt3 = t5-t4;
		ofs<<"Elapsed time: "<<fixed<<dt3.count()<<" msec"<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!) Exiting file error in binary search tree."<<endl;
	BST.reset();

	//Binary Search Tree AVL
	BinarySearchTreeAVL BSTAVL;
	ifs.open("input.txt");
	if(ifs.is_open()){
		while(ifs>>string){
			string.fix();
			BSTAVL.insert(string.getData());
		}
		ifs.close();
	}
	else
		cerr<<"(!) Reading file error trying to initialize binary search tree AVL."<<endl;
	ofs.open("output.txt", ios::out | ios::app);
	if(ofs.is_open()){
		ofs<<"BINARY SEARCH TREE AVL RESULTS:"<<endl;
		auto t6=high_resolution_clock::now();
		for(int indx=0;indx<CEILING;indx++)
			if(!BSTAVL.search(Q[indx].getData(),ofs))
				ofs<<"\""<<Q[indx].getData()<<"\" not found"<<endl;
		auto t7=high_resolution_clock::now();
		duration<double,milli> dt4 = t7-t6;
		ofs<<"Elapsed time: "<<fixed<<dt4.count()<<" msec"<<endl<<endl;
		ofs.close();
	}
	else
		cerr<<"(!) Exiting file error in binary search tree AVL."<<endl;
	BSTAVL.reset();

	//Hash Table
	//.
	//.
	//.

	return 0;
}

//>Min metras xrono stis sinartiseis, ase na to kanw egw stin main
//>Kane tis public search bool
//>Stis search vale na pernei orisma ostream &o giati i ektipwsi prepei na ginetai se file
//oxi sto cout apparetita. Na mporw diladi UARR.search(string,ofs);
//>Stis search min exeis alla orismata pera apo to string kai to ostream&
//an xriazontai ta int, int pou exeis pros to paron, valta stin private
//>Vale reset function se oles tis domes
//>An thes help sto hash table pes mou, na isxuoun ta analoga apo panw kai gi auto
