/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	main.cpp
********************************************/

#include <fstream>
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h> 

#include "SkewHeap.cpp"
#include "LeftistHeap.cpp"
#include "Timer.cpp"

int main()
{	

	Timer time; 

	SkewHeap skew;
	LeftistHeap leftist;
	
	int elements;
	
	double LeftistHeap[5], SkewHeap[5], LeftistNorm, SkewNorm, LeftistOperation[5], SkewOperation[5],
	SkewOperationNorm, LeftistOperationNorm, Operations[40000];

	int numberOfElements[4] = {50000, 100000, 200000, 400000};

	for(int m = 0; m < 4; m++)
	{
		LeftistNorm = 0;
		SkewNorm = 0;
		LeftistOperationNorm = 0; 
		SkewOperationNorm = 0;
	
		cout << endl << "Number of Operations = " << numberOfElements[m] << endl;

		for(int i = 1; i <= 5; i++)
		{
			LeftistHeap[i] = 0; 
			SkewHeap[i] = 0; 
			LeftistOperation[i] = 0; 
			SkewOperation[i] = 0;

			srand(i);
			elements = numberOfElements[m]; 
			int numbers[elements];
		
			for(int k = 0; k < elements; k++)
			{
				numbers[k] = (rand()%(4*elements)) + 1; 
			}

			time.start();
 
			for(int p = 0; p < elements; p++)
			{
				skew.insert(numbers[p]); 
			}
	
			SkewHeap[i] = time.stop();
			SkewNorm += SkewHeap[i];
	
			cout << "Skew Heap time with seed " << i << " was: " << SkewHeap[i] << endl;
			
			time.start();
		
			for(int b = 0; b < elements; b++)
			{
				leftist.insert(numbers[b]);
			}
	
			LeftistHeap[i] = time.stop(); 
			LeftistNorm += LeftistHeap[i]; 

			cout << "Leftist Heap time with seed " << i << " was: " << LeftistHeap[i] << endl; 

			int OperationNumbers[int((elements*.10)+1)];
		
			for(int q = 0; q < (.10*elements); q++)
			{
				Operations[q] = double(((rand()%100))/100.0);
				OperationNumbers[q] = (rand()%(4*elements)) + 1; 
			}

			time.start();
			
			for(int t = 0; t < (.10*elements); t++)
			{
				if(Operations[t] >= 0 && Operations[t] < .50)
				{
					skew.deleteMin();
				}

				else if(Operations[t] >= .50 && Operations[t] <= 1)
				{
					skew.insert(OperationNumbers[t]);
				}
			}
			
			SkewOperation[i] = time.stop();
			SkewOperationNorm += SkewOperation[i]; 
	
			cout << "Skew Heap Operation time for seed " << i << " was: " << SkewOperation[i] << endl;

			
			time.start(); 
		
			for(int u = 0; u < (.10*elements); u++)
			{
				if(Operations[u] >= 0 && Operations[u] < .50)
				{
					leftist.deleteMin();
				}
				
				else if(Operations[u] >= .5 && Operations[u] <= 1)
				{
					leftist.insert(OperationNumbers[u]);
				}
			}
				
			LeftistOperation[i] = time.stop();
			LeftistOperationNorm += LeftistOperation[i];
	
			cout << "Leftist Heap Operation time for seed " << i << " was: " << LeftistOperation[i] << endl << endl;

		}

		cout << "Leftist Heap time average: " << (LeftistNorm/5) << endl; 
		cout << "Skew Heap time average: " << (SkewNorm/5) << endl;
		cout << "Leftist Heap Operation time average: " << (LeftistOperationNorm/5) << endl; 
		cout << "Skew Heap Operation time average: " << (SkewOperationNorm/5) << endl; 
		
	}


}








