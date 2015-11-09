/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 3
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 
#include <stdio.h>
#include <stdlib.h> 

#include "Timer.cpp"
#include "HashTable.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 

	myFile.open(argv[1]); 

	HashTable hash(myFile, false);
		
	hash.print(); 
	
	myFile.close(); 

	return 0; 
}

// 300005
// 240004
// 180003
// 120002
