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
	Timer time; 

	srand(30); 
    	int randomNumber; 
    	
	for(int i = 0; i < 300005; i++)
	{ 
       		randomNumber = rand();	
	}

	myFile.open(argv[1]); 

	HashTable hash(myFile, true); 
	hash.print(); 

	myFile.close(); 

	return 0; 
}

