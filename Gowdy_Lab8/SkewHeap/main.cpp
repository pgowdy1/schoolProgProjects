/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string> 

#include "SkewHeap.cpp"

int main(int argc, char* argv[])
{	
	std::ifstream myFile; 
	
	myFile.open(argv[1]);	 
	 
	SkewHeap heap;
	SkewHeap *head;
	head = NULL;

	heap.readData(myFile); 

	int menuChoice = 0;
	int userInput;
  
	while(menuChoice != -1)
	{
		cout << "Enter a number for the command you wish to perform: \n"
		<< "1- readDataFile\n" 
		<< "2- insert\n"
		<< "3- deleteMin\n"
		<< "4- preOrder\n"
		<< "5- inOrder\n"
		<< "6- levelOrder\n"
		<< "7- exit\n";

	cin >> menuChoice; 

	if(menuChoice == 1)
	{
		int i = 0; 
		while(heap.dataArray[i] != -1337)
		{
			head = heap.insert(heap.dataArray[i], head);
			i++;
		}
		cout << "The numbers in the data file have been inserted into the Heap.\n";
	}	

	if(menuChoice == 2)
	{
		cout << "What number would you like to insert?\n";
		cin >> userInput; 
		head = heap.insert(userInput, head); 
	}

	if(menuChoice == 3)
	{
		head = heap.deleteMin(head); 
	}

	if(menuChoice == 4)
	{
		heap.preOrder(head); 
		cout << endl;
	}

	if(menuChoice == 5)
	{
		
		heap.inOrder(head);
		cout << endl; 
	}
/*
	if(menuChoice == 6)
	{
		heap.levelOrder();
	}
*/
	if(menuChoice == 7)
	{
		menuChoice = -1;
		cout << "Exiting...\n";  
	} 

	}

	return 0; 
}
