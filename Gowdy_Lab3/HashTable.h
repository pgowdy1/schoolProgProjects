/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 3
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
	bool flagArray[]; 

public:
	HashTable();
	HashTable(std::istream& is, bool quadratic);
	virtual ~HashTable(); 
	
	void insertLinear(int hashCheck, int value); 
	void print(); 
	void insertQuadratic(int quadFunc, int value);
   	void removeLinear(int hashCheck, int numberToRemove);
	void removeQuadratic(int quadFunc, int numberToRemove); 
	bool isFull(); 
	bool contains(int value);   
 
	
};
	
#include "HashTable.cpp" 
#endif
