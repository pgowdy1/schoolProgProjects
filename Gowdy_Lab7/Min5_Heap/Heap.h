/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 6
*	Heap.h
********************************************/

#ifndef _HEAP
#define _HEAP
#include <cmath>

class Heap
{

	private:
		int* elements; 
		int arraySize; 
		int heapSize; 
		int getRightChildIndex(int index);
		int getLeftChildIndex(int index);
		int getMin();
		int getParentIndex(int index); 

	public:

		Heap();
		Heap(std::istream& is);
		~Heap();  
		bool isEmpty(); 
		void insert(int value); 
		int heapUp(int index);
		void deleteMin();
		void deleteMax();
		void remove(int value); 
		void levelOrder();
 
};


#include "Heap.cpp"
#endif
