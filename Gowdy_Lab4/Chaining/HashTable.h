/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 2
*	HashTable.h
********************************************/

#ifndef _HASHTABLE
#define _HASHTABLE


#include <iostream>
#include <fstream>
#include "HashList.h"

class HashTable
{

private: 

	HashList** theHashTable; 
	int tableSize; 
	HashList* headPtr; 

public:
	HashTable();
	HashTable(std::istream& is);
	virtual ~HashTable(); 

	void insert(int value);
	void print();
   	void remove(int numberToRemove);
	bool find(int value);  
	bool isEmpty(); 

	int hash(int value); 
	
};
	
#include "HashTable.cpp" 
#endif
