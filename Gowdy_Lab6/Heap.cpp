/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 6
*	Heap.cpp
********************************************/

using namespace std;

Heap::Heap()
{
	elements = new int[500];
	heapSize = 0; 
	arraySize = 500; 

	for(int i = 0; i < 500; i++)
	{
		elements[i] = -1337;
	} 
}

Heap::Heap(std::istream& is)
{
	elements = new int[500];
	heapSize = 0;
	arraySize = 500; 

	for(int i = 0; i < 500; i++)
	{
		elements[i] = -1337;
	}

	int numberToInsert;
	
	
	while (is >> numberToInsert)
	{
		elements[heapSize] = numberToInsert;
		heapSize = heapSize + 1; 
	}

	for(int i = ceil((heapSize - 1 / 5) - 1); i >= 0; i--)
	{
		heapUp(i); 
	}
	
	cout << endl; 
}

Heap::~Heap()
{
	delete[] elements;
}

bool Heap::isEmpty()
{
	if(heapSize == 0)
	{
		return true;
	}

	else
	{
		return false;
	} 
}
	
int Heap::getParentIndex(int index)
{
	return (index - 1) / 5; 
}

int Heap::getLeftChildIndex(int index)
{
	return 5 * index + 1; 
}

int Heap::getRightChildIndex(int index)
{
	return 5 * index + 5; 
}

void Heap::deleteMin()
{
	if(!isEmpty())
	{
		elements[0] = elements[heapSize-1];
		elements[heapSize-1] = -1337;
		heapSize = heapSize - 1; 

		int currentValue = 0;
		int currentChild = 1; 
	
		while(elements[currentChild] != -1337)
		{
			int smallestValue = currentChild; 

			for(int i = 1; i <= 5; i++)
			{
				if(elements[currentChild+i] < elements[smallestValue])
				{
					smallestValue = currentChild + i; 
				}
			}
			
			int tempValue = elements[currentValue]; 
			elements[currentValue] = elements[smallestValue];
			elements[smallestValue] = tempValue; 
			currentValue = smallestValue;
			currentChild = currentValue * 5 + 1; 
		}
	}
}

void Heap::deleteMax()
{
	int maxValue = (heapSize - 1 / 5) + 1; 
	int currentValue = maxValue; 

	while(currentValue < heapSize)
	{
		if(elements[currentValue] > elements[maxValue])
		{
			maxValue = currentValue; 
		}
		
		currentValue++; 
	}
	
	elements[maxValue] = elements[heapSize - 1]; 
	elements[heapSize - 1] = -1337;
	heapSize = heapSize - 1; 
}			

int Heap::getMin()
{
	if(isEmpty())
	{
		cout << "The heap is Empty."; 
	}

	else
	{
		return elements[0]; 
	}
}

void Heap::insert(int value)
{
	if(heapSize == arraySize)
	{
		cout << "The heap is out of space."; 
	}

	else
	{
		heapSize++; 
		elements[heapSize - 1] = value;
		heapUp(heapSize - 1); 
	}
}

void Heap::remove(int value)
{
	int currentValue = heapSize - 1; 

	while(currentValue >= 0)
	{
		while(elements[currentValue] == value)
		{
			elements[currentValue] = elements[heapSize - 1];
			elements[heapSize - 1] = -1337;
			heapSize = heapSize - 1; 
		}

		heapUp(currentValue);
		currentValue = currentValue - 1; 
	}
}

int Heap::heapUp(int index)
{
	if(elements[5 * index + 1] == -1337)
	{
		return index;
	}
	
	int firstChild = heapUp(5 * index + 1);
	int smallestValue = firstChild;

	if(elements[5 * index + 2] != -1337)
	{
		int secondChild = heapUp(5 * index + 2);
	
		if(elements[secondChild] < elements[firstChild])
		{
			smallestValue = secondChild;
		}
	
		if(elements[5 * index + 3] != -1337)
		{
			int thirdChild = heapUp(5 * index + 3);
		
			if(elements[thirdChild] < elements[smallestValue])
			{
				smallestValue = thirdChild;
			}

			if(elements[5 * index + 4] != -1337)
			{
				int fourthChild = heapUp(5 * index + 4);
				
				if(elements[fourthChild] < elements[smallestValue])
				{
					smallestValue = fourthChild;
				}

				if(elements[5 * index + 5] != -1337)
				{
					int fifthChild = heapUp(5 * index + 5);
		
					if(elements[fifthChild] < elements[smallestValue])
					{
						smallestValue = fifthChild;
					}
				}
			}
		}
	}

	if(elements[smallestValue] < elements[index])
	{
		int tempValue = elements[index];
		elements[index] = elements[smallestValue];
		elements[smallestValue] = tempValue;
		heapUp(smallestValue);
	}

	return index;
}

void Heap::levelOrder()
{
	for(int i = 0; i < heapSize; i++)
	{
		if(i == 1)
		{
			cout << endl; 
		}		
		
		if(i == 6)
		{
			cout << endl; 
		}
		
		if(i == 26)
		{
			cout << endl;
		}
		
		if(i == 126)
		{
			cout << endl; 
		}

		if(elements[i] != -1337)
		{		
			cout << elements[i] << " ";
		}
	
		if((i % 5 == 0) && (i > 5))
		{
			cout << "- ";
		}
	}
	
	cout << endl; 
}













































