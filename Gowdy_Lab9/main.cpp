
/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 9
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "MinMaxHeap.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	MinMaxHeap heap(myFile);  

	int menuChoice = 0;
	int userInput;
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n" 
		<< "1- insert\n"
		<< "2- deleteMin\n"
		<< "3- deleteMax\n"
		<< "4- levelOrder\n"
		<< "5- exit\n";

	cin >> menuChoice; 

	if(menuChoice == 1)
	{
		cout << "What number would you like to insert?\n";
		cin >> userInput; 
		heap.insert(userInput); 
	}

	if(menuChoice == 2)
	{
		cout << "The minimum value in the tree has been deleted.\n"; 
		heap.deleteMin(); 
	}

	if(menuChoice == 3)
	{
		cout << "The maximum value in the tree has been deleted.\n";
		heap.deleteMax();
	}

	if(menuChoice == 4)
	{
		heap.levelOrder();
	}

	if(menuChoice == 5)
	{
		menuChoice = -1;
		cout << "Exiting...\n";  
	} 

	}

	myFile.close();

	return 0; 
}

