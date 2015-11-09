/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 7
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

#include "BinarySearchTree.h"
#include "Heap.h"
#include "Timer.cpp"

int main(int argc, char* argv[])
{	

	Timer time; 
	BinarySearchTree BST;
	Heap heap;
	
	int randomNumber;
	double timeAmount;
	
	int dataSet1[50]; 
	
	for(int i = 1; i <= 5; i++)
	{	
		for(int j = 0; j < 51; j++)
		{
			dataSet1[j] = rand() % 200000 + 1; 		
		}
		
		for(int n = 0; n < 51; n++)
		{
			time.start();
			BST.insert(dataSet1[n]);
		}	
		
		cout << "The seed " << i << " took " << time.stop() << endl; 	 
	}

/*	for(int o = 1; o <= 5; o++)
	{	
		for(int p = 1; p < 50000; p++)
		{
			srand(o); 
			time.start(); 
		
			randomNumber = rand();
			heap.insert(randomNumber); 		
		}
		
		cout << "The seed " << o << " took " << time.stop();		 
	}
*/

	return 0; 
}

