/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "Llist.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	Llist theList(myFile); 
	theList.remove(0); 
	theList.remove(21); 
	theList.insert(10); 
	theList.insert(44);
	theList.insert(12);
	theList.remove(8); 
	theList.find(10);
	theList.find(2301);
	theList.print();  

	myFile.close(); 

	return 0; 
}

