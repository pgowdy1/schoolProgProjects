/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	SkewHeap.cpp
********************************************/
using namespace std;
#include <iostream>
#include <cstdlib>

class SkewHeap
{ 
	
	public:

		SkewHeap* rightChild;
		SkewHeap* leftChild;
		SkewHeap* parent; 
		int value;
		int dataArray[500000];  

		SkewHeap()
		{
			value = 0;
			rightChild = NULL;
			leftChild = NULL;
			parent = NULL; 
		}

		void readData(std::istream& is)
		{
			for(int i = 0; i < 500000; i++)
			{
				dataArray[i] = -1337; 
			}
			
			int numberToAdd;
			int counter = 0; 
			
			while(is >> numberToAdd)
			{
				dataArray[counter] = numberToAdd; 
				counter++;
			}
		}

		SkewHeap* merge(SkewHeap* tree1, SkewHeap* tree2)
		{
			SkewHeap* tempHeap; 
	
			if(tree1 == NULL)
			{
				return tree2; 
			}
		
			else if (tree2 == NULL)
			{
				return tree1;
			}
	
			else
			{
				if(tree1->value > tree2->value)
				{
					tempHeap = tree1;
					tree1 = tree2; 
					tree2 = tempHeap; 
				}

				tempHeap = tree1->leftChild;
				tree1->leftChild = tree1->rightChild;
				tree1->rightChild = tempHeap;
				tree1->leftChild = merge(tree2, tree1->leftChild); 
			}
	
			return tree1; 
		}

		SkewHeap* insert(int number, SkewHeap* rootPtr)
		{
			SkewHeap* tempHeap;

			tempHeap = new SkewHeap;
			tempHeap->value = number;
			rootPtr = merge(rootPtr, tempHeap);
	
			cout << "The value " << number << " has been added." << endl; 
			return rootPtr; 
		}

		void preOrder(SkewHeap* rootPtr)
		{
			if(rootPtr == NULL)
			{
				return;
			}

			else
			{
				cout << rootPtr->value << " "; 
				preOrder(rootPtr->leftChild);
				preOrder(rootPtr->rightChild);
			}

		}

		void inOrder(SkewHeap* rootPtr)
		{
			if(rootPtr == NULL)
			{
				return;
			}
	
			else
			{
				inOrder(rootPtr->leftChild); 
				cout << rootPtr->value <<" ";
				inOrder(rootPtr->rightChild);
			}
		}

		SkewHeap* deleteMin(SkewHeap* rootPtr)
		{
			if(rootPtr == NULL)
			{
				return NULL;
			}
			
			SkewHeap* tempHeap1;
			SkewHeap* tempHeap2;

			tempHeap1 = rootPtr->leftChild;
			tempHeap2 = rootPtr->rightChild; 

			tempHeap1 = merge(tempHeap1, tempHeap2);

			return tempHeap1; 
		}	
		
}; 

