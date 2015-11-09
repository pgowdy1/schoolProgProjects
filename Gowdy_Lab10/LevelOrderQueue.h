/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	LevelOrderQueue.h
********************************************/

#ifndef _LEVEL_ORDER_QUEUE
#define _LEVEL_ORDER_QUEUE

#include "Node.h"

class LevelOrderQueue
{
	private:
		Node** queueArray = new Node*[500];
	public:
		
		int sizeOfArray = 500;
		int counter = 0;

		LevelOrderQueue();
		void push(Node* firstNode);
		Node* pop();
		Node* peek();
		bool isEmpty();
};

#endif
