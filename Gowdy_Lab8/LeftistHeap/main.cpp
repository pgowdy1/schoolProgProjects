/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "LeftistHeap.cpp"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]);	

	LeftistHeap heap(myFile); 

	int menuChoice = 0;
	int userInput;
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n" 
		<< "1- insert\n"
		<< "2- deleteMin\n"
		<< "3- preOrder\n"
		<< "4- inOrder\n"
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
		heap.deleteMin(); 
	}

	if(menuChoice == 3)
	{
		heap.preOrder(heap.getRoot()); 
		cout << endl;
	}

	if(menuChoice == 4)
	{
		
		heap.inOrder(heap.getRoot());
		cout << endl; 
	}
/*
	if(menuChoice == 5)
	{
		heap.levelOrder();
	}
*/
	if(menuChoice == 6)
	{
		menuChoice = -1;
		cout << "Exiting...\n";  
	} 

	}

	myFile.close(); 
	return 0; 
}

