
/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 6
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "Heap.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	Heap heap(myFile);  

	int menuChoice = 0;
	int userInput;
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n" 
		<< "1- insert\n"
		<< "2- remove\n"
		<< "3- deleteMin\n"
		<< "4- deleteMax\n"
		<< "5- levelOrder\n"
		<< "6- exit\n";

	cin >> menuChoice; 

	if(menuChoice == 1)
	{
		cout << "What number would you like to insert?\n";
		cin >> userInput; 
		heap.insert(userInput); 
	}

	if(menuChoice == 2)
	{
		cout << "What number would you like to remove?\n";
		cin >> userInput; 
		heap.remove(userInput); 
	}

	if(menuChoice == 3)
	{
		cout << "The minimum value in the tree has been deleted.\n"; 
		heap.deleteMin(); 
	}

	if(menuChoice == 4)
	{
		cout << "The maximum value in the tree has been deleted.\n";
		heap.deleteMax();
	}

	if(menuChoice == 5)
	{
		heap.levelOrder();
	}

	if(menuChoice == 6)
	{
		menuChoice = -1;
		cout << "Exiting...\n";  
	} 

	}

	myFile.close();

	return 0; 
}

