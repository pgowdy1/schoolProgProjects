/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	SkewHeap.cpp
********************************************/
using namespace std;
#include <iostream>
#include <cstdlib>

struct Node2
{
	Node2* rightChild;
	Node2* leftChild;
	Node2* parent; 
	int value; 	 	
};

class SkewHeap
{ 
	
	public:
		
		Node2* root; 
		int dataArray[500000];  

		SkewHeap()
		{
			root = NULL; 
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

		Node2* merge(Node2* tree1, Node2* tree2)
		{
			Node2* tempHeap; 
	
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

		void insert(int number)
		{

			Node2* tempHeap = new Node2;
			tempHeap->value = number;
			root = merge(root, tempHeap);
		}

		void preOrder(Node2* rootPtr)
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

		void inOrder(Node2* rootPtr)
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

		void deleteMin()
		{
			if(root == NULL)
			{
				return;
			}

			root = merge(root->leftChild, root->rightChild); 
		}	
		
}; 

