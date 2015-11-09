/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 11
*	Set.cpp
********************************************/
#include "Set.h" 
#include <iostream>

using namespace std;

Set::Set(int size)
{
	headSet = new int[size]; 

	for(int i = 0; i < size; i++)
	{
		headSet[i] = -1337; 
	}
}

int Set::find(int value)
{
	if(headSet[value] < 0)
	{
		return value;
	}

	else
	{
		return (headSet[value] = find(headSet[value])); 
	}
}

void Set::combine(int firstSet, int secondSet)
{
	if(firstSet == secondSet)
	{
		return;
	}

	if(headSet[firstSet] < headSet[secondSet])
	{
		headSet[firstSet] = secondSet;
	}

	else
	{
		if(headSet[firstSet] == headSet[secondSet])
		{
			int value = headSet[firstSet];
			headSet[firstSet] = value--; 
		}

		headSet[secondSet] = firstSet;
	}
}

void Set::print(int size)
{ 
	for(int i = 0; i < size; i++)
	{
		cout << headSet[i] << " ";
	}

	cout << endl; 
}
