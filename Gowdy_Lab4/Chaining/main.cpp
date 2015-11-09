/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 2
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
	srand(5); 
    	int randomNumber; 
	double timeAmount; 

	myFile.open(argv[1]); 

	time.start();
	
	HashTable hash(myFile);
		
	for(int i = 0; i < 120002; i++)
	{ 
       		randomNumber = rand();
		hash.insert(randomNumber); 	
	}
	
	timeAmount = time.stop(); 
	time.printTime(timeAmount);  
	
	myFile.close(); 

	return 0; 
}
