/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "BinomialQueue.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	BinomialQueue queue; 

	int fileInt;

	int menuChoice = 0;
	int userInput;

	while(myFile >> fileInt)
	{
		queue.insert(fileInt);
	}
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n" 
		<< "1- insert\n"
		<< "2- deleteMin\n"
		<< "3- levelOrder\n"
		<< "4- exit\n";

	cin >> menuChoice; 
	cout << endl;

	if(menuChoice == 1)
	{
		cout << "What number would you like to insert?\n";
		cin >> userInput; 
		queue.insert(userInput); 
	}

	else if(menuChoice == 2)
	{
		queue.deleteMin(); 
		cout << "The minimum value in the tree has been deleted.\n";
	}

	else if(menuChoice == 3)
	{ 
		cout << "********************************************************************" << endl;
		queue.levelOrder(); 
		cout << endl;
		cout << "********************************************************************" << endl << endl;
	}

	else if(menuChoice == 4)
	{
		menuChoice = -1; 
		cout << "Exiting..." << endl;
	}

	else
	{
		cout << "That is not a valid choice. Please select again." << endl;
	}
	

	}

	myFile.close();

	return 0; 
}

