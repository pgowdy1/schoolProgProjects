/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 2
*	HashTable.cpp
********************************************/
#include <fstream>
#include <iostream>

using namespace std; 

HashTable::HashTable() : headPtr(NULL)
{
} //default constructor

HashTable::HashTable(std::istream& is) : headPtr(NULL)
{
	int numberToAdd;

	is >> tableSize;
	cout << "The size of the table is " << tableSize << ".\n"; 

	theHashTable = new HashList*[tableSize];

	for(int i = 0; i < tableSize; i++)
	{
		theHashTable[i] = NULL;
	}

	while(is >> numberToAdd)
	{
		insert(numberToAdd);  
	}
}	

HashTable::~HashTable()
{
	for(int i = 0; i < tableSize; i++)
	{
	HashList* curNode = theHashTable[i];
		while(curNode != NULL)
		{
			HashList* temp = curNode; 
			
			if(curNode->getNext() == NULL)
			{
				delete temp;
				break;
			}			
			
			curNode = curNode->getNext(); 
			delete temp; 
		}
	}
} 

void HashTable::insert(int value) 
{
	if(find(value) == true)
	{
		return;
	}

	else
	{
		int hashValue = (value % tableSize);
		if((theHashTable[hashValue] == NULL))
		{
			theHashTable[hashValue] = new HashList(value); 
		}
		else
		{
			HashList* newEntry = theHashTable[hashValue];
			
			while(newEntry->getNext() != NULL)
			{
				if(newEntry->getValue() == value)
				{
					return; 
				}
				newEntry = newEntry->getNext();
			}
	
			if(newEntry->getNext() == NULL)
			{
				newEntry->setNext(new HashList(value));
			}
		}
	}
}

void HashTable::print()
{
	HashList* curNode = theHashTable[0];	
	
	for(int i = 0; i < tableSize; i++)
	{
		curNode = theHashTable[i];
		cout << i << ": ";
		while(curNode != NULL)
		{	
			cout << curNode->getValue() << " ";
			curNode = curNode->getNext();
		}	
		cout << "\n";
	}
	cout << "\n"; 
}

bool HashTable::isEmpty()
{
	bool checkFlag = true;  
	
	for(int i = 0; i < tableSize; i++)
	{
		if(theHashTable[i] != NULL)
		{
			checkFlag = false; 
		}
	}

	return checkFlag; 
}		
		
void HashTable::remove(int numberToRemove)
{
	HashList* prevNode = NULL;
	HashList* delNode = NULL; 
	
	for(int i = 0; i < tableSize; i++)
	{
		headPtr = theHashTable[i]; 

		if(headPtr->getValue() == numberToRemove)
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
			if(delNode->getValue() == numberToRemove)
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

	cout << "\n"; 
}

bool HashTable::find(int value)
{
	if(isEmpty() == false)
	{
		HashList* curNode = NULL;
		int checkVar;
		
		for(int i = 0; i < tableSize; i++)
		{
			curNode = theHashTable[i];
			if(theHashTable[i] != NULL)
			{
				if(curNode->getValue() == value)
				{
					checkVar = curNode->getValue();
				}
					while(curNode->getNext() != NULL)
					{
						if(curNode->getValue() == value)
						{
							checkVar = curNode->getValue(); 
						}
						curNode = curNode->getNext(); 
					}

				if(curNode->getValue() == value) 
				{
					checkVar = curNode->getValue(); 	
				}
			}
		}

		if(checkVar == value)
		{ 
			cout << "The value " << value << " has been found.\n"; 
			return true;
		}
	
		else
		{
			return false;
		}
	}

	else
	{
		return false; 
	}
}

int HashTable::hash(int value) 
{
	int hashNumber = find(value); 
	
	hashNumber = (hashNumber % tableSize); 
 	
	return hashNumber; 
}
			

	
 	





















