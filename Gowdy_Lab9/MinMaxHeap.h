/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 9
*	MinMaxHeap.h
********************************************/

#ifndef _MINMAXHEAP
#define _MINMAXHEAP
#include <cmath>

class MinMaxHeap
{

	private:
		

	public:

		MinMaxHeap();
		MinMaxHeap(std::istream& is);  
		bool isEmpty(); 
		void insert(int value);
		void trickleDown(int position);
		void trickleDownMin(int position);
		void trickleDownMax(int position); 
		void bubbleUp(int position);
		void bubbleUpMin(int position);
		void bubbleUpMax(int position);
		void deleteMin();
		void deleteMax();
		void levelOrder();
 
		int minMaxHeap[2000];
};


#include "MinMaxHeap.cpp"
#endif
