/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	Node.h
********************************************/


#ifndef _NODE
#define _NODE

class Node
{

private: 
	int 	item; 
	Node*	leftChildPtr;
	Node*	rightChildPtr;  

public: 
	Node(); 
	Node(const int number, Node* leftPtr, Node* rightPtr); 
	
	void setItem(const int numb);  
	int getItem() const; 

	bool isLeaf() const; 

	Node* getLeftChildPtr(); 
	Node* getRightChildPtr(); 
	
	void setLeftChildPtr(Node* leftPtr); 
	void setRightChildPtr(Node* rightPtr); 

}; 

#include "Node.cpp"
#endif

