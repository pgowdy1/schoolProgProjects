/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 3
*	HashTable.cpp
********************************************/
#include <fstream>
#include <iostream>

using namespace std; 

HashTable::HashTable()
{
} //default constructor

HashTable::HashTable(std::istream& is, bool quadratic)
{
	int numberToAdd;

	is >> tableSize;
	
	cout << "The size of the table is " << tableSize << ".\n"; 

	for(int i = 0; i < tableSize; i++)
	{
		flagArray[i] = false;
	}

	theHashTable = new HashList*[tableSize]; 

	for(int j = 0; j < tableSize; j++)
	{
		theHashTable[j] = NULL; 
	}

	if(quadratic == true)
	{
		while(is >> numberToAdd)
		{
			insertQuadratic(0, numberToAdd);  
		}
	}

	else
	{
		while(is >> numberToAdd)
		{
			insertLinear(numberToAdd, numberToAdd);
		}
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

void HashTable::insertLinear(int hashCheck, int value) 
{
	int hashValue = (hashCheck % tableSize); 

	if((theHashTable[hashValue] == NULL) && (flagArray[hashValue] == false))
	{
		theHashTable[hashValue] = new HashList(value); 
	}

	else
	{
		insertLinear(hashCheck + 1, value); 
	}
}

void HashTable::insertQuadratic(int quadFunc, int value)
{
	if(quadFunc <= tableSize)
	{
		int hashValue = ((value + (quadFunc * quadFunc)) % tableSize); 
	
		if((theHashTable[hashValue] == NULL) && (flagArray[hashValue] == false))
		{
			theHashTable[hashValue] = new HashList(value); 
		}
	
		else
		{ 
			insertQuadratic(quadFunc + 1, value);
		}
	}

	else
	{
		cout << "Could not insert the number " << value << " to the table.\n";
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
		
void HashTable::removeLinear(int hashCheck, int numberToRemove)
{
	int hashValue = (hashCheck % tableSize); 

	if((theHashTable[hashValue]->getValue() == numberToRemove) && (flagArray[hashValue] == false))
	{
		theHashTable[hashValue]->setValue(-1); 
		flagArray[hashValue] = true;  
	}

	else
	{
		removeLinear(hashValue + 1, numberToRemove); 
	}
}

void HashTable::removeQuadratic(int quadFunc, int numberToRemove) 
{
	if(contains(numberToRemove))
	{
		int hashValue = ((numberToRemove + (quadFunc * quadFunc)) % tableSize); 
	
		if((theHashTable[hashValue]->getValue() == numberToRemove) && (flagArray[hashValue] == false))
		{
			theHashTable[hashValue]->setValue(-1); 
			flagArray[hashValue] = true;  
		}
	
		else
		{ 
			removeQuadratic(quadFunc + 1, numberToRemove);
		}
	}
	
}

bool HashTable::isFull()
{
	int checkArray = 0; 
	
	while(checkArray <= tableSize)
	{
		if(theHashTable[checkArray] == NULL)
		{
			cout << "The hash table is NOT full.\n";
			return false; 
		}
		checkArray++;
	}

	cout << "The hash table is full.\n"; 
	return true; 
}

bool HashTable::contains(int value)
{
	int checkArray = 0; 
	
	while(checkArray < tableSize)
	{
		if(theHashTable[checkArray]->getValue() == value)
		{
			return true; 
		}
		checkArray++; 
	}

	cout << "The hash table does NOT contain the value " << value << ".\n"; 
	return false;
}

void HashTable::setTableSize(int sizeOfTable)
{
	tableSize = sizeOfTable;
}
	
int HashTable::getTableSize()
{
	return tableSize; 
}		
	




















