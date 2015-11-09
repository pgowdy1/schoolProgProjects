/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 5
*	BinarySearchTree.h
********************************************/

#ifndef _BINARY_SEARCH_TREE
#define _BINARY_SEARCH_TREE

#include "Node.h"

class BinarySearchTree
{

private: 
	int 	item; 
	Node*	rootPtr;
	  
public: 

	BinarySearchTree(); 
	BinarySearchTree(std::istream& is);
	
	void insert(int value); 
	void remove(int value); 
	Node* removeHelper(Node* ptr); //Helper for Remove
	Node* removeLeftmostNode(Node* ptr, int inorderSuccessor); //Helper for Remove
	Node* removeValue(Node* subTreePtr, int target, bool& success); //Helper for Remove

	bool isEmpty();
	void preOrder();
	void preOrderHelper(Node* ptr);
	void inOrder();
	void inOrderHelper(Node* ptr); 
	void levelOrder(); 
	void levelOrderHelper(Node* ptr); 
	void levelOrderLevel(Node* ptr, int level);
	Node* search(int value); 
	void deleteMin();
	void deleteMinHelper(Node* ptr); 
	void deleteMax();
	void deleteMaxHelper(Node* ptr); 
	int getHeight();
	int heightHelper(Node* ptr);
	
	
/*	
	Node* search(int value);  
	bool deleteMax(); 
	void preOrder();
	void inOrder();
	void levelOrder(); 	
*/
}; 

#include "BinarySearchTree.cpp"
#endif

