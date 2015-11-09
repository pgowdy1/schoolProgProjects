/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 3
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "HashTable.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	HashTable hash(myFile, true); 
	hash.print(); 
	hash.removeQuadratic(8, 8); 
	hash.removeQuadratic(72, 72);
	hash.contains(7);  
	hash.print(); 
	hash.isFull(); 
	hash.insertQuadratic(4,4);
	hash.insertQuadratic(1902831,1902831);
	hash.print(); 
	hash.isFull(); 
	hash.removeQuadratic(1920,1920);
	hash.contains(7); 
	hash.contains(192);
	hash.removeQuadratic(26,26);
	hash.insertQuadratic(26,26);
	hash.print(); 

	myFile.close(); 

	return 0; 
}

