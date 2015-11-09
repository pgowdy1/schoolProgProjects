/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 3
*	HashList.h
********************************************/

#ifndef _HASHLIST
#define _HASHLIST

class HashList {

private:

	int value; 
	HashList* nextPtr;  

public:
	HashList();
	HashList(int number);
	
	int getValue();
	void setValue(int number);
	HashList* getNext(); 
	void setNext(HashList* ptr); 

};


#include "HashList.cpp"
#endif

