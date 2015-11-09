/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 2
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

	HashTable hash(myFile); 
	hash.print(); 

	myFile.close(); 

	return 0; 
}

