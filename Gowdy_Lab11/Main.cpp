/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 11
*	Main.cpp
********************************************/
#include "MinSpanningTree.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream myFile; 

	myFile.open("data.txt"); 
	
	string curLine; 
	int i = 0; 
	int sizeOfRead; 
	int* array = new int[10]; 

	struct aMatrix
	{
		int** matrix; 
		
		aMatrix();
		
		aMatrix(int value)
		{
			matrix = new int*[value]; 

			for(int i = 0; i < value; i++)
			{
				matrix[i] = new int[value]; 
			}

			for(int i = 0; i < value; i++)
			{
				for(int j = 0; j < value; j++)
				{
					matrix[i][j] = -1337;
				}
			}
		}
	};

	 
	int* sizeOfList;
	int numberOfMatrices = 0; 
	int flag = -1; 
	int graphNum, graphSize; 

	aMatrix** ML;  
	aMatrix* store;

	while(getline(myFile, curLine))
	{
		stringstream ls(curLine);
		int tempValue; 
	
		while(ls >> tempValue)
		{
			if(flag == -1)
			{
				graphNum = tempValue; 
				ML = new aMatrix*[graphNum];
				sizeOfList = new int[graphNum];
				flag++; 
			}
	
			else
			{
				if(flag == 0)
				{
					graphSize = tempValue;
					store = new aMatrix(graphSize);
					sizeOfList[numberOfMatrices] = graphSize; 
					flag++; 
				}
	
				else if(flag == graphSize*graphSize)
				{
					store->matrix[(int)floor((flag-1)/graphSize)][(flag-1)%graphSize] = tempValue; 
					ML[numberOfMatrices] = store;
					numberOfMatrices++;
					flag = 0;
				}

				else
				{
					store->matrix[(int)floor((flag-1)/graphSize)][(flag-1)%graphSize] = tempValue; 
					flag++;
				}
			}
		}
	} 
	
	for(int i = 0; i < numberOfMatrices; i++)
	{
		MinSpanningTree curMatrix(ML[i]->matrix, sizeOfList[i]); 
		cout << "Graph " << i+1 << ":" << endl; 
		
		curMatrix.print();
		cout << endl;
	}
}
						




























