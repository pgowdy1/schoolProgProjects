/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 11
*	MinSpanningTree.cpp
********************************************/
#ifndef MIN_SPANNING_TREE_H
#define MIN_SPANNING_TREE_H

#include <cstdlib>

class MinSpanningTree
{
	
	public: 
	
		int** adjMatrix;
		int sizeOfVertices;
		int sizeOfList;

		MinSpanningTree();
		MinSpanningTree(int** firstMatrix, int size); 
		void execute();
		void print(); 

		struct Edge
		{
			int pairs[2];
			int weightOfEdge;

			bool operator<(Edge& edge)
			{
				if(weightOfEdge < edge.weightOfEdge)
				{
					return true;
				}
				
				else
				{
					return false;
				}
			}

			bool operator>(Edge& edge)
			{
				if(weightOfEdge > edge.weightOfEdge)
				{
					return true;
				}
			
				else
				{
					return false;
				}
			}
		};
	
		Edge* listOfEdges;

		struct comparator
		{
			bool operator()(Edge& left, Edge& right)
			{
				return left.weightOfEdge > right.weightOfEdge;
			}
		};

};

#endif		
		
