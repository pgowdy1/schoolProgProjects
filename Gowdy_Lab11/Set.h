/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 11
*	Set.h
********************************************/
#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <cstdlib> 
#include <vector>

class Set 
{
	private: 
		int* headSet; 

	public: 
		Set(int size); 
		int find(int value); 
		void combine(int firstSet, int secondSet); 
		void print(int size); 
}; 

#endif
