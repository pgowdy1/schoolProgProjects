/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	BinomialQueue.cpp
********************************************/

#include <iostream>
#include <cstdlib>
using namespace std; 

BinomialQueue::BinomialQueue()
{
	for(int i = 0; i < 500; i++)
	{
		rootArray[i] = NULL; 
	}
}		

void BinomialQueue::merge(Node* firstNode)
{
	if(rootArray[firstNode->order] != NULL)
	{
		int pOrder = firstNode->order; 
		Node* tempNode = unionOperation(firstNode, rootArray[firstNode->order]); 
		merge(tempNode);
		rootArray[pOrder] = NULL;
	}

	else
	{
		rootArray[firstNode->order] = firstNode; 
	} 	
}
Node* BinomialQueue::createNode(int value)
{
	Node* tempNode = new Node;
	tempNode->key = value; 
	
	cout << "The node with value " << value << " has been created." << endl; 

	return tempNode;
}
	
void BinomialQueue::insert(int value)
{
	Node* tempNode = new Node(value);
	merge(tempNode); 
}


void BinomialQueue::revertList(Node* firstNode)
{
	if(firstNode->siblingPtr != NULL)
	{
		revertList(firstNode->siblingPtr);
		(firstNode->siblingPtr)->siblingPtr = firstNode;
	}

	else
	{
		tailPtr = firstNode;
	}
}
	
Node* BinomialQueue::unionOperation(Node* firstNode, Node* secondNode)
{
	if(firstNode->key < secondNode->key)
	{
		firstNode->cAppend(secondNode);
		return firstNode;
	}

	else
	{
		secondNode->cAppend(firstNode);
		return secondNode;
	}
}

void BinomialQueue::link(Node* firstNode, Node* secondNode)
{
	firstNode->parentPtr = secondNode;
	firstNode->siblingPtr = secondNode->childPtr;
	
	secondNode->childPtr = firstNode;
	secondNode->order = secondNode->order + 1;
}

void BinomialQueue::levelOrder()
{
	for(int i = 0; i < size; i++)
	{
		if(rootArray[i] != NULL)
		{
			cout << rootArray[i]->key << endl;
			
			if(rootArray[i]->childPtr != NULL)
			{
				sQueue->push(rootArray[i]->childPtr);
			}

		while(!sQueue->isEmpty())
		{
			cout << sQueue->peek()->key << " ";
	
			if(sQueue->peek()->childPtr != NULL)
			{
				cQueue->push(sQueue->peek()->childPtr);
			}

			if(sQueue->peek()->siblingPtr != NULL)
			{
				sQueue->push(sQueue->peek()->siblingPtr);
			}
			
			sQueue->pop();

			if(sQueue->isEmpty() && !cQueue->isEmpty())
			{
				cout << endl;
				sQueue = cQueue; 
				cQueue = new LevelOrderQueue();
			}
		}
		
		cout << endl << "--------------------------------------------------------------------" << endl;
		}
	}
}

int BinomialQueue::findNumberOfTrees(Node* headPtr)
{
	if(headPtr == NULL)
	{
		return 0;
	}

	int numTrees = 1;

	Node* tempNode; 
	tempNode = headPtr;
	
	while(tempNode->siblingPtr != NULL)
	{
		tempNode = tempNode->siblingPtr;
		numTrees++; 
	}

	return numTrees; 
}

void BinomialQueue::deleteMin()
{
	Node* minValue = NULL;
	
	for(int i = 0; i < size; i++)
	{
		if(minValue == NULL)
		{
			if(rootArray[i] != NULL)
			{
				minValue = rootArray[i]; 
			}
		}

		else
		{
			if(rootArray[i] != NULL)
			{
				if(rootArray[i]->key < minValue->key)
				{
					minValue = rootArray[i];
				}
			}
		}
	}

	if(minValue == NULL)
	{
		return; 
	}

	for(int i = 0; i < size; i++)
	{
		if(rootArray[i] == minValue)
		{
			rootArray[i] = NULL;
		}
	}

	Node* tempNode = minValue->childPtr; 
	Node* nextNode = NULL;
		
		while(tempNode != NULL)
		{
			nextNode = tempNode->siblingPtr; 
			tempNode->siblingPtr = NULL;
	
			merge(tempNode);
			tempNode = nextNode;
		}
}






	
	






