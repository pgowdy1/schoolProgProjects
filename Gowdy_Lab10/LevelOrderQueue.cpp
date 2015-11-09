/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	LevelOrderQueue.cpp
********************************************/

#include "LevelOrderQueue.h"

LevelOrderQueue::LevelOrderQueue()
{

}

void LevelOrderQueue::push(Node* firstNode)
{
	if(counter == sizeOfArray-1)
	{
		Node** tempNode = new Node*[sizeOfArray*2];

		for(int i = 0; i < sizeOfArray; i++)
		{
			tempNode[i] = queueArray[i];
		}

		queueArray = tempNode;
		sizeOfArray = sizeOfArray*2;
	}

	queueArray[counter] = firstNode;
	counter++;
}

Node* LevelOrderQueue::pop()
{
	Node* tempNode = queueArray[0];

	for(int i = 0; i < sizeOfArray-1; i++)
	{
		queueArray[i] = queueArray[i+1];
	}

	counter--;
	return tempNode;
}

Node* LevelOrderQueue::peek()
{
	return queueArray[0];
}

bool LevelOrderQueue::isEmpty()
{
	if(counter != 0)
	{
		return false;
	}
	
	else
	{
		return true;
	}
}
