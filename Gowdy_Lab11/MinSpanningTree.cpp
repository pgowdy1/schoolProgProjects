/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 11
*	MinSpanningTree.cpp
********************************************/
#include "MinSpanningTree.h"
#include "Set.h"
#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

MinSpanningTree::MinSpanningTree(int** firstMatrix, int size)
{
	adjMatrix = firstMatrix; 
	sizeOfVertices = size; 
	execute(); 
}

void MinSpanningTree::execute()
{
	Set set(sizeOfVertices);
	std::priority_queue<Edge, std::vector<Edge>, comparator> queue;

	listOfEdges = new Edge[5];
	sizeOfList = 5; 

	for(int i = 0; i < sizeOfList; i++)
	{
		listOfEdges[i].pairs[0] = -1337; 
		listOfEdges[i].pairs[1] = -1337;
	}

	for(int i = 0; i < sizeOfVertices; i++)
	{
		for(int j = 0; j < sizeOfVertices; j++)
		{
			if(adjMatrix[i][j] != 0)
			{
				Edge storage;
				
				storage.pairs[0] = i;
				storage.pairs[1] = j; 
	
				storage.weightOfEdge = adjMatrix[i][j];
				queue.push(storage); 
			}
		}
	}

	Edge edge; 
	int a = 0;
	int value1, value2; 

	while(a < sizeOfVertices - 1)
	{
		edge = queue.top();
		queue.pop();
		
		value1 = edge.pairs[0];
		value2 = edge.pairs[1]; 

		int firstSet = set.find(value1); 
		int secondSet = set.find(value2); 

		if(firstSet != secondSet)
		{
			set.combine(firstSet, secondSet);
	
			Edge storage2; 
			storage2.pairs[0] = firstSet; 
			storage2.pairs[1] = secondSet; 

			listOfEdges[a] = storage2; 

			if(a == sizeOfList - 1)
			{
				Edge* storage3 = new Edge[sizeOfList*2];

				for(int i = 0; i < sizeOfList; i++)
				{
					storage3[i].pairs[0] = listOfEdges[i].pairs[0];
					storage3[i].pairs[1] = listOfEdges[i].pairs[1];
				}

				for(int i = sizeOfList; i < sizeOfList*2; i++)
				{
					storage3[i].pairs[0] = -1337;
					storage3[i].pairs[1] = -1337; 
				}

				listOfEdges = storage3;
				sizeOfList = sizeOfList*2; 
			}

			a++;
		}
	}
}


void MinSpanningTree::print()
{
	for(int i = 0; i < sizeOfList; i++)
	{
		if(listOfEdges[i].pairs[0] != -1337)
		{
			cout << "(" << listOfEdges[i].pairs[0] << "," << listOfEdges[i].pairs[1] << ")";
		}
	}
	cout << endl;
}


























