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
	srand(45); 
    	int randomNumber; 
	double timeAmount; 

	myFile.open(argv[1]); 

	time.start();
	
	HashTable hash(myFile, false);
		
	for(int i = 0; i < 300005; i++)
	{ 
       		randomNumber = rand();
		hash.insertLinear(randomNumber, randomNumber); 	
	}

	timeAmount = time.stop(); 
	time.printTime(timeAmount);  
	
	myFile.close(); 

	return 0; 
}

// 300005 
// 240004
// 180003
// 120002
