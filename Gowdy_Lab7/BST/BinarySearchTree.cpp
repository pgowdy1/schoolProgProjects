/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 5
*	BinarySearchTree.cpp
********************************************/

using namespace std; 

BinarySearchTree::BinarySearchTree() : rootPtr(NULL)
{
}

BinarySearchTree::BinarySearchTree(std::istream& is) : rootPtr(NULL)
{
	int numberToAdd; 
	
	while(is >> numberToAdd)
	{
		insert(numberToAdd);	
	}
}

bool BinarySearchTree::isEmpty()
{
	if(rootPtr == NULL)
	{
		return true;
	}
	
	else
	{
		return false; 
	}
}	

void BinarySearchTree::insert(int value)
{
	Node* tempPtr = new Node();

	if(isEmpty())
	{
		rootPtr = tempPtr;
		rootPtr->setItem(value); 
	}
		
	else if(rootPtr->isLeaf())
	{
		if(value <= rootPtr->getItem())
		{
			rootPtr->setLeftChildPtr(tempPtr);
			tempPtr->setItem(value); 
		}
	
		if(value > rootPtr->getItem())
		{
			rootPtr->setRightChildPtr(tempPtr);
			tempPtr->setItem(value); 	
		}
	}

	else if(rootPtr->isLeaf() == false)
	{
		delete tempPtr; 
		tempPtr = rootPtr; 

		while(tempPtr->isLeaf() == false)
		{
			if(value <= tempPtr->getItem())
			{
				if(tempPtr->getLeftChildPtr() != NULL)
				{
					tempPtr = tempPtr->getLeftChildPtr();
				} 
				else
				{
					break;
				}
			}

			if(value > tempPtr->getItem())
			{ 
				if(tempPtr->getRightChildPtr() != NULL)
				{
					tempPtr = tempPtr->getRightChildPtr(); 
				}
				else
				{
					break; 
				}
			}
		}
	 
		Node* newPtr = new Node(); 
			
		if(value <= tempPtr->getItem())
		{			 
			tempPtr->setLeftChildPtr(newPtr); 
			newPtr->setItem(value); 
		}
		
		if(value > tempPtr->getItem()) 
		{
			tempPtr->setRightChildPtr(newPtr); 
			newPtr->setItem(value); 
		}
		
	}
}

void BinarySearchTree::preOrder()
{
	preOrderHelper(rootPtr);
	cout << endl;
}
	
void BinarySearchTree::preOrderHelper(Node* ptr) 
{
	if(!isEmpty())
	{
		int value = ptr->getItem();
	
		cout << value << " "; 
	
		if(ptr->getLeftChildPtr() != NULL)
		{
			preOrderHelper(ptr->getLeftChildPtr()); //recursively trickles down tree to left
		}

		if(ptr->getRightChildPtr() != NULL)
		{
			preOrderHelper(ptr->getRightChildPtr()); //recursively trickles down tree to right
		}
	}
}

void BinarySearchTree::inOrder()
{
	inOrderHelper(rootPtr);
	cout << endl; 
}

void BinarySearchTree::inOrderHelper(Node* ptr)
{
	if(!isEmpty())
	{
		if(ptr->getLeftChildPtr() != NULL)
		{
			inOrderHelper(ptr->getLeftChildPtr()); //recursively trickles down tree to left
		}
		
		int value = ptr->getItem(); 
		cout << value << " "; 

		if(ptr->getRightChildPtr() != NULL)
		{
			inOrderHelper(ptr->getRightChildPtr()); //recursively trickles down tree to right
		}
	}
}

void BinarySearchTree::levelOrder()
{
	levelOrderHelper(rootPtr);
	cout << endl;
}

void BinarySearchTree::levelOrderHelper(Node* ptr)
{
	int height = getHeight();
	int i; 

 	for(i = 1; i <= height; i++)
	{
		levelOrderLevel(rootPtr, i);
	}

}

void BinarySearchTree::levelOrderLevel(Node* ptr, int level)
{

	if(ptr == NULL)
	{
		return;
	}

	if(level == 1)
	{
		printf("%d ", ptr->getItem());
	}

	else if (level > 1)
	{
		levelOrderLevel(ptr->getLeftChildPtr(), level - 1);
		levelOrderLevel(ptr->getRightChildPtr(), level - 1);
  	}
}

Node* BinarySearchTree::search(int value)
{
	Node* tempPtr = rootPtr; 
	
	while(!(tempPtr->getItem() == value)) 
	{
		if(tempPtr->getItem() > value)
		{
			if(tempPtr->getLeftChildPtr() == NULL) //if get to the end of the tree and not found, throw exception
			{
				cout << "Count not find the number " << value << " " << endl; 
			}
			else
			{
				tempPtr = tempPtr->getLeftChildPtr();
			}
		}

		if(tempPtr->getItem() < value) 
			{
			if(tempPtr->getRightChildPtr() == NULL) //if get to the end of the tree and not found, throw exception
			{
				cout << "Could not find the number " << value << " " << endl; 
			}
			else
			{
				tempPtr = tempPtr->getRightChildPtr(); 
			}
		}
	}
		
	return tempPtr;	 
}

void BinarySearchTree::deleteMin()
{
	if(!isEmpty())
	{
		deleteMinHelper(rootPtr); 
	}
}

void BinarySearchTree::deleteMinHelper(Node* ptr)
{
	Node* tempPtr = ptr; 
	
	while (tempPtr->getLeftChildPtr() != NULL) 
	{
    		tempPtr = tempPtr->getLeftChildPtr();
  	}

  	remove(tempPtr->getItem());  
}

void BinarySearchTree::deleteMax()
{
	if(!isEmpty())
	{
		deleteMaxHelper(rootPtr); 
	}
}

void BinarySearchTree::deleteMaxHelper(Node* ptr)
{
	Node* tempPtr = ptr; 

	while (tempPtr->getRightChildPtr() != NULL)
	{
		tempPtr = tempPtr->getRightChildPtr();
	}

	remove(tempPtr->getItem());  
}

void BinarySearchTree::remove(int value)
{
	bool success = false;
	int aValue = value;
	rootPtr = removeValue(rootPtr, aValue, success); //the removeValue accepts three parameters, rootptr, the inputted Key and a bool. 
							//the bool will tell if the remove was successful, if it wasn't successful, an exception is thrown and caught
	if(success == false) 
	{
		cout << "Could not remove the value " << value << " " << endl; 
	}		
	
}

Node* BinarySearchTree::removeValue(Node* subTreePtr, int target, bool& success) //helper method for remove
{
	if(subTreePtr == NULL) 
	{
		success = false; 
		return NULL; 
	}
	else if(subTreePtr->getItem() == target)
	{
		subTreePtr = removeHelper(subTreePtr); 
		success = true; 
		return subTreePtr; 
	}
	else if(subTreePtr->getItem() > target) 
	{
		Node* tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success); //recursive method that seeks target for base case
		subTreePtr->setLeftChildPtr(tempPtr); 
		return subTreePtr; 
	}
	else
	{
		Node* tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success); //recursive method that seeks target for base case
		subTreePtr->setRightChildPtr(tempPtr); 
		return subTreePtr; 
	}
}


Node* BinarySearchTree::removeHelper(Node* ptr)
{
	if(ptr->isLeaf()) //case 1 - the node is a leaf
	{
		delete ptr;
		ptr = NULL; 
		return ptr; 
	}	
	
	else if((ptr->getRightChildPtr() == NULL && ptr->getLeftChildPtr() != NULL) || (ptr->getRightChildPtr() != NULL && ptr->getLeftChildPtr() == NULL)) //case 2 - 1 child
	{
		if(ptr->getLeftChildPtr() != NULL) 
			Node* nodeToConnectPtr = ptr->getLeftChildPtr(); 

		else
		{
			Node* nodeToConnectPtr = ptr->getRightChildPtr(); 
			delete ptr; 
			ptr = NULL; 
			return nodeToConnectPtr; 
		}
	}

	else //case 3 - the node has two children
	{
		int newNodeValue; 
		Node* tempPtr = removeLeftmostNode(ptr->getRightChildPtr(), newNodeValue);
		ptr->setRightChildPtr(tempPtr); 
		ptr->setItem(newNodeValue);
		return ptr;
	}
}


Node* BinarySearchTree::removeLeftmostNode(Node* ptr, int inorderSuccessor)  
{
	if(ptr->getLeftChildPtr() == NULL) 
	{
		inorderSuccessor = ptr->getItem(); 
		return removeHelper(ptr);
	}
	
	else
	{
		ptr->setLeftChildPtr(removeLeftmostNode(ptr->getLeftChildPtr(), inorderSuccessor));
		return ptr; 
	}
}

int BinarySearchTree::heightHelper(Node* ptr)
{
	if (ptr == NULL)
	{
		return 0;
	}

	else
	{
/* compute the height of each subtree */
	int leftHeight = heightHelper(ptr->getLeftChildPtr());
	int rightHeight = heightHelper(ptr->getRightChildPtr());
 
	/* use the larger one */
		if (leftHeight > rightHeight)
		{
			return(leftHeight + 1);
		}
		
		else 
		{
			return(rightHeight + 1);
		}
	}
} 

int BinarySearchTree::getHeight()
{
	return heightHelper(rootPtr);
}








