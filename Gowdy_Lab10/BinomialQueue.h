/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	BinomialQueue.h
********************************************/

#ifndef _BINOMIAL_QUEUE
#define _BINOMIAL_QUEUE

#include "Node.h"
#include "LevelOrderQueue.cpp"

#define size 500

class BinomialQueue
{

private: 
  
	Node*	rootArray[size];
	Node* 	headPtr;
	Node* 	tailPtr;	 
	  
public: 

	BinomialQueue(); 
	BinomialQueue(std::istream& is);
	void insert(int value);
	Node* unionOperation(Node* firstNode, Node* secondNode);
	void deleteMin(); 
	void merge(Node* firstNode);

	void levelOrder();
	LevelOrderQueue* cQueue = new LevelOrderQueue(); 
	LevelOrderQueue* sQueue = new LevelOrderQueue(); 	

	Node* createNode(int value); 
	void revertList(Node* firstNode);
	void link(Node* firstNode, Node* secondNode); 
	int findNumberOfTrees(Node* headPtr);
	

}; 

#include "BinomialQueue.cpp"
#endif

