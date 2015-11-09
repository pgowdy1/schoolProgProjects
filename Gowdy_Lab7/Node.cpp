/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	Node.cpp
********************************************/

Node::Node()
{
} //default constructor

Node::Node(const int number, Node* leftPtr, Node* rightPtr) : item(number), leftChildPtr(NULL), rightChildPtr(NULL)
{
} //constructor

void Node::setItem(const int numb)
{
	item = numb; 
}

int Node::getItem() const
{
	return item; 
}

Node* Node::getLeftChildPtr()
{
	return leftChildPtr; 
}
	
Node* Node::getRightChildPtr()
{
	return rightChildPtr;
}

void Node::setRightChildPtr(Node* rightPtr)
{
	rightChildPtr = rightPtr; 
}

void Node::setLeftChildPtr(Node* leftPtr)
{
	leftChildPtr = leftPtr;
}

bool Node::isLeaf() const
{
	if((leftChildPtr == NULL) && (rightChildPtr == NULL))
	{
		return true;
	}

	else
	{
		return false;
	}
}


