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
	int 	dataNumber; 
	Node*	nextNode; 

public: 
	Node();
	Node(const int number); 
	void setNum(const int number); 
	void setNext(Node* nextNodePtr); 
	int getItem() const;
	Node* getNext() const; 

}; 

#include "Node.cpp"
#endif

