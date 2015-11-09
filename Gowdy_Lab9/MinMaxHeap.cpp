/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 9
*	MinMaxHeap.cpp
********************************************/
#include <math.h>

using namespace std;

MinMaxHeap::MinMaxHeap()
{
	minMaxHeap[0] = 0; 
}

MinMaxHeap::MinMaxHeap(std::istream& is)
{
	int tempValue = 0;
	
	while(is >> tempValue)
	{
		minMaxHeap[0] = minMaxHeap[0] + 1;
		minMaxHeap[minMaxHeap[0]] = tempValue;
	}

	for(int i = minMaxHeap[0]; i >= 1; i--)
	{
		trickleDown(i);
	}

	cout << endl; 
}

void MinMaxHeap::trickleDown(int position)
{
	if(int(log2(position)) % 2 == 0)
	{
		trickleDownMin(position);
	}

	else
	{
		trickleDownMax(position);
	}
}

void MinMaxHeap::trickleDownMax(int position)
{
	if(minMaxHeap[0] >= 2*position)
	{
		int large = 2*position;

		if(minMaxHeap[0] >= (2*position)+1)
		{
		
			if(minMaxHeap[large] < minMaxHeap[(2*position)+1])
			{
				large = 2*position+1;
			}

			if(minMaxHeap[0] >= 2*((2*position)+1))
			{
				if(minMaxHeap[large] < minMaxHeap[2*((2*position)+1)])
				{
					large = 2*((2*position)+2);
				}

				if(minMaxHeap[0] >= (2*((2*position)+1))+1)
				{			
					if(minMaxHeap[large] > minMaxHeap[(2*((2*position)+1))+1])
					{
						large = (2*((2*position)+1))+1;
					}
				}
			}
		}

		if(minMaxHeap[0] >= 4*position)
		{
			if(minMaxHeap[0] >= (4*position)+1)
			{
	
				if(minMaxHeap[large] < minMaxHeap[(4*position)+1])
				{
					large = (4*position)+1;
				}
			}
			if(minMaxHeap[large] < minMaxHeap[(4*position)+1])
			{
					large = 4*position;
			}
			
		}
	

		if(large >= (4*position))
		{
			if(minMaxHeap[large] > minMaxHeap[position])
			{
				int tempValue = minMaxHeap[large];
				minMaxHeap[large] = minMaxHeap[position];
				minMaxHeap[position] = tempValue;

				if(minMaxHeap[large] < minMaxHeap[large/2])
				{
					int tempValue2 = minMaxHeap[large];
					minMaxHeap[large] = minMaxHeap[large/2];
					minMaxHeap[large/2] = tempValue2;
				}

				trickleDownMax(large);
			}
		}

		else
		{
			if(minMaxHeap[large] > minMaxHeap[position])
			{
				int tempValue3 = minMaxHeap[large];
				minMaxHeap[large] = minMaxHeap[position];
				minMaxHeap[position] = tempValue3; 
			}
		}
	}
}


void MinMaxHeap::trickleDownMin(int position)
{
	if(minMaxHeap[0] >= 2*position)
	{
		int small = 2*position;

		if(minMaxHeap[0] >= (2*position)+1)
		{
		
			if(minMaxHeap[small] > minMaxHeap[(2*position)+1])
			{
				small = 2*position+1;
			}

			if(minMaxHeap[0] >= 4*position+2)
			{
				if(minMaxHeap[small] > minMaxHeap[(4*position)+2])
				{
					small = 4*position+2;
				}

				if(minMaxHeap[0] >= 4*position+3)
				{			
					if(minMaxHeap[small] > minMaxHeap[(4*position)+3])
					{
						small = 3*position+3;
					}
				}
			}
		}

		if(minMaxHeap[0] >= 4*position)
		{
			if(minMaxHeap[small] > minMaxHeap[4*position])
			{
				small = 4*position;
			}

			if(minMaxHeap[0] >= 4*position+1)
			{
				if(minMaxHeap[small] > minMaxHeap[(4*position)+1])
				{
					small = 4*position+1;
				}
			}
		}
	

		if(small >= (4*position))
		{
			if(minMaxHeap[small] < minMaxHeap[position])
			{
				int tempValue = minMaxHeap[small];
				minMaxHeap[small] = minMaxHeap[position];
				minMaxHeap[position] = tempValue;

				if(minMaxHeap[small] > minMaxHeap[small/2])
				{
					int tempValue2 = minMaxHeap[small];
					minMaxHeap[small] = minMaxHeap[small/2];
					minMaxHeap[small/2] = tempValue2;
				}

			trickleDownMin(small);
			}
		}

		else
		{
			if(minMaxHeap[small] < minMaxHeap[position])
			{
				int tempValue3 = minMaxHeap[small];
				minMaxHeap[small] = minMaxHeap[position];
				minMaxHeap[position] = tempValue3; 
			}
		}
	}
}


bool MinMaxHeap::isEmpty()
{
	if(minMaxHeap[0] == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void MinMaxHeap::deleteMin()
{
	if(minMaxHeap[0] > 1)
	{
		if(minMaxHeap[0] == 2)
		{
			minMaxHeap[1] = minMaxHeap[2];
			minMaxHeap[0] = minMaxHeap[0] - 1;
			return;
		}

		int smallestVal = 2;
		int size = minMaxHeap[0];

		if(minMaxHeap[0] >= 7)
		{
			size = 7;
		}

		for(int i = 3; i <= size; i++)
		{
			if(minMaxHeap[i] < minMaxHeap[smallestVal])
			{
				smallestVal = i; 
			}
		}

		if(minMaxHeap[minMaxHeap[0]] <= minMaxHeap[smallestVal])
		{
			minMaxHeap[1] = minMaxHeap[minMaxHeap[0]];
			minMaxHeap[0] = minMaxHeap[0] - 1; 
		}

		else
		{
			minMaxHeap[1] = minMaxHeap[smallestVal];
	
			if(smallestVal < 4)
			{
				minMaxHeap[smallestVal] = minMaxHeap[minMaxHeap[0]];
				minMaxHeap[0] = minMaxHeap[0] - 1; 
			}

			else
			{
				if(minMaxHeap[minMaxHeap[0]] <= minMaxHeap[smallestVal/2])
				{
					minMaxHeap[smallestVal] = minMaxHeap[minMaxHeap[0]];
					minMaxHeap[0] = minMaxHeap[0] - 1; 
					trickleDown(smallestVal);
				}

				else
				{
					minMaxHeap[smallestVal] = minMaxHeap[smallestVal/2];
					minMaxHeap[smallestVal/2] = minMaxHeap[minMaxHeap[0]];
					minMaxHeap[0] = minMaxHeap[0] - 1;
					trickleDown(smallestVal);
				}
			}
		}
	}

	else
	{
		minMaxHeap[0] = 0;
	}
}

void MinMaxHeap::deleteMax()
{
	if(isEmpty())
	{
		return; 
	}
	
	else if(minMaxHeap[0] == 1)
	{
		minMaxHeap[0] = 0;
		return;
	}

	else
	{
		int maxValue = 2;
		if(minMaxHeap[0] >= 3)
		{
			if(minMaxHeap[2] < minMaxHeap[3])
			{
				maxValue = 3; 
			}
		}
	
		minMaxHeap[maxValue] = minMaxHeap[minMaxHeap[0]];
		minMaxHeap[0] = minMaxHeap[0] - 1; 
		trickleDown(maxValue);
	}	 
}

void MinMaxHeap::bubbleUp(int position)
{
	if(int(log2(position))%2 == 0)
	{
		if((position > 1) && (minMaxHeap[position] > minMaxHeap[position/2]))
		{
			int tempValue = minMaxHeap[position];
			minMaxHeap[position] = minMaxHeap[position/2];
			minMaxHeap[position/2] = tempValue;
			
			bubbleUpMax(position/2);
		}

		else
		{
			bubbleUpMin(position);
		}
	}

	else
	{
		if((position > 1) && (minMaxHeap[position] < minMaxHeap[position/2]))
		{
			int tempValue2 = minMaxHeap[position];
			minMaxHeap[position] = minMaxHeap[position/2];
			minMaxHeap[position/2] = tempValue2; 
			bubbleUpMin(position/2);
		}

		else
		{
			bubbleUpMax(position);
		}
	}
}

void MinMaxHeap::bubbleUpMax(int position)
{
	if(position > 3)
	{
		if(minMaxHeap[position] > minMaxHeap[((position/2)/2)])
		{
			int tempValue = minMaxHeap[position];
			minMaxHeap[position] = minMaxHeap[((position/2)/2)];
			minMaxHeap[((position/2)/2)] = tempValue;
			
			bubbleUpMax(((position/2)/2));
		}
	}
}
		
void MinMaxHeap::bubbleUpMin(int position)
{
	if(position > 3)
	{
		if(minMaxHeap[position] < minMaxHeap[((position/2)/2)])
		{
			int tempValue = minMaxHeap[position];
			minMaxHeap[position] = minMaxHeap[((position/2)/2)];
			minMaxHeap[((position/2)/2)] = tempValue;
			
			bubbleUpMax(((position/2)/2));
		}
	}
}



void MinMaxHeap::insert(int value)
{
	minMaxHeap[0] = minMaxHeap[0] + 1; 
	minMaxHeap[minMaxHeap[0]] = value;
	bubbleUp(minMaxHeap[0]);
}

void MinMaxHeap::levelOrder()
{
	int curLevel = 1;
	
	for(int i = 1; i <= minMaxHeap[0]; i++)
	{
		if(i >= 2*curLevel)
		{		
			cout << endl;
			curLevel = curLevel*2;
		}
		cout << minMaxHeap[i] << " ";
	}
	cout << endl;
}	













































