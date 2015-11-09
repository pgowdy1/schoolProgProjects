/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "BinarySearchTree.h"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]); 

	BinarySearchTree bTree(myFile);  

	int menuChoice = 0;
	int userInput;
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n" 
		<< "1- insert\n"
		<< "2- remove\n"
		<< "3- deleteMin\n"
		<< "4- deleteMax\n"
		<< "5- preOrder\n"
		<< "6- inOrder\n"
		<< "7- levelOrder\n"
		<< "8- exit\n";

	cin >> menuChoice; 

	if(menuChoice == 1)
	{
		cout << "What number would you like to insert?\n";
		cin >> userInput; 
		bTree.insert(userInput); 
	}

	if(menuChoice == 2)
	{
		cout << "What number would you like to remove?\n";
		cin >> userInput; 
		bTree.remove(userInput); 
	}

	if(menuChoice == 3)
	{
		cout << "The minimum value in the tree has been deleted.\n"; 
		bTree.deleteMin(); 
	}

	if(menuChoice == 4)
	{
		cout << "The maximum value in the tree has been deleted.\n";
		bTree.deleteMax();
	}
	
	if(menuChoice == 5)
	{
		bTree.preOrder(); 
	}
	
	if(menuChoice == 6)
	{
		bTree.inOrder();
	}

	if(menuChoice == 7)
	{
		bTree.levelOrder();
	}

	if(menuChoice == 8)
	{
		menuChoice = -1;
		cout << "Exiting...\n";  
	} 

	}

	myFile.close();

	return 0; 
}

