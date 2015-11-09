/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	Llist.h
********************************************/


#ifndef _LINKED_LIST
#define _LINKED_LIST

#include <fstream>
#include <iostream>
#include "Node.h"

class Llist 
{

private: 
	Node* headPtr; 
	int itemCount;  

public:
	Llist();
	Llist(std::istream& is); 
	virtual ~Llist(); 

	//ifstream reader(
	bool isEmpty() const; 
	void clear();
	void insertHelper(Node* node, int newNumber); 
	void insert(int newNumber);
	Node* findHelper(Node* node, int numberToFind); 
	Node* find(int numberToFind);
	void print(); 
	void printHelper(Node* node);
	
	void remove(int numberToRemove); 	

};

#include "Llist.cpp" 
#endif
