/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	Node.h
********************************************/


#ifndef _NODE
#define _NODE

class Node
{

private: 
	 

public: 

	int key = -1337;
	int order = 0; 
	Node* parentPtr = NULL;
	Node* childPtr = NULL;
	Node* siblingPtr = NULL; 

	void levelOrder();
	void cAppend(Node* firstNode);
	void sAppend(Node* firstNode);
	Node();
	Node(int value); 

}; 

#include "Node.cpp"
#endif

