/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	Llist.cpp
********************************************/
#include <iostream>
#include <fstream>

using namespace std;  

Llist::Llist() : headPtr(NULL), itemCount(0)
{
} //default constructor

Llist::Llist(std::istream& is) : headPtr(NULL), itemCount(0)
{
	int numberToBeStored = 0; 
	
	while(is >> numberToBeStored)
	{ 
		insert(numberToBeStored);
		cout << "The number " << numberToBeStored << " has been inserted into the List.\n";  
	}
}
	
Llist::~Llist()
{
	clear(); 
} //deconstructor 

void Llist::clear()
{
}

bool Llist::isEmpty() const
{
	if(headPtr == NULL)
	{
		return true;
	}

	else
	{
		return false; 
	}
}

void Llist::insert(int newNumber)
{
	if(isEmpty())
	{
		headPtr = new Node;
		headPtr->setNum(newNumber);
		headPtr->setNext(NULL); 
	}
	
	else
	{
		insertHelper(headPtr, newNumber);
	}		
} 
			
void Llist::insertHelper(Node* node, int newNumber)
{
	if(node->getNext() != NULL)
	{
		insertHelper(node->getNext(), newNumber);
	}

	else
	{
		Node* newNode = new Node;
		node->setNext(newNode);  
		node->getNext()->setNum(newNumber);
		node->getNext()->setNext(NULL);
	}
	
}

Node* Llist::find(int numberToFind)
{
	if(isEmpty())
	{
		std::cout << "The list is empty.\n"; 
		Node* foundNode = new Node;
		foundNode = NULL;
		
		return foundNode;  
	}

	else
	{ 
		Node* foundNode = findHelper(headPtr, numberToFind);
		return foundNode;
	}
	 	
}

Node* Llist::findHelper(Node* node, int numberToFind)
{
	if(node->getItem() == numberToFind)
	{
		std::cout << "The number " << numberToFind << " has been found.\n"; 
		return node; 	
	}

	if(node->getNext() == NULL)
	{
		std::cout << "This list does not contain the number " << numberToFind << ".\n"; 
		return NULL;
	}
	
	else
	{
		findHelper(node->getNext(), numberToFind); 
	}
}

void Llist::print()
{
	if(isEmpty())
	{
		cout << "The list is empty.\n"; 
	}
	
	if(headPtr->getNext() == NULL)
	{
		cout << headPtr->getItem(); 
	}
	
	else
	{
		cout << headPtr->getItem() << ", ";
		printHelper(headPtr->getNext());
	}
}

void Llist::printHelper(Node* node)
{
	if(node->getNext() == NULL)
	{
		cout << node->getItem() << "\n"; 
	}

	else
	{
		cout << node->getItem() << ", "; 
		printHelper(node->getNext());
	}
}

void Llist::remove(int numberToRemove)
{
	Node* prevNode = NULL;
	Node* delNode = NULL; 

	if(headPtr->getItem() == numberToRemove)
	{
		delNode = headPtr;
		
		headPtr = delNode->getNext();
		delete delNode;
		cout << "The number " << numberToRemove << " has been removed.\n";
		return;
	}

	prevNode = headPtr;
	delNode = headPtr->getNext(); 

	while(delNode != NULL)
	{
		if(delNode->getItem() == numberToRemove)
		{
			prevNode->setNext(delNode->getNext());

			if(delNode->getNext() == NULL)
			{
				prevNode->setNext(NULL); 
			}
			
			delete delNode;
			cout << "The number " << numberToRemove << " has been removed.\n"; 
			break;
		}

		prevNode = delNode;
		delNode = delNode->getNext(); 
	}
}

		















