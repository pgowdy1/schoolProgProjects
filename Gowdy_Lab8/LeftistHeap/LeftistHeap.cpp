/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 8
*	LeftistHeap.cpp
********************************************/
using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iostream>

struct Node
{
	Node* leftChild;
	Node* rightChild;
	int value, rank;
};

class LeftistHeap
{ 
	private:
		Node* root;	

	public:

		Node* getRoot()
		{
			return root; 
		}

		LeftistHeap(std::istream& is)
		{
			root = NULL;
			int numberToAdd;
	
			while(is >> numberToAdd)
			{
				insert(numberToAdd);
			}
		}

		LeftistHeap()
		{
			root = NULL;
		}

		 
		Node* merge(Node* tree1, Node* tree2)
		{
			if(tree1 == NULL)
			{
				return tree2; 
			}
		
			else if (tree2 == NULL)
			{
				return tree1;
			}
	
			else if(tree1->value > tree2->value)
			{
				Node* tempNode = tree1;
				tree1 = tree2; 
				tree2 = tempNode; 	
			}
			
			tree1->rightChild = merge(tree1->rightChild, tree2);
		
			if((tree1->leftChild == NULL)&&(tree1->rightChild != NULL))
			{
				tree1->leftChild = tree1->rightChild;
				tree1->rightChild = NULL;
				tree1->rank = 1; 
			}

			else
			{
				if(tree1->leftChild->rank < tree1->rightChild->rank)
				{
					Node* tempNode = tree1->leftChild;
					tree1->leftChild = tree1->rightChild;
					tree1->rightChild = tempNode; 		
				}
		
				tree1->rank = tree1->rightChild->rank+1;
			}

			return tree1; 
		}

		void insert(int number)
		{
			Node* node = new Node;
			
			node->value = number; 

			node->leftChild = NULL;
			node->rightChild = NULL;
			node->rank = 1; 

			root = merge(root, node);
		}

		void preOrder(Node* rootPtr)
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

		void inOrder(Node* rootPtr)
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
			if(root != NULL)
			{
				root = merge(root->rightChild, root->leftChild);
			}
		}	
		
}; 

