/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 1
*	Node.cpp
********************************************/

Node::Node() : nextNode(NULL)
{
} //default constructor

Node::Node(const int inputNumber) : dataNumber(inputNumber), nextNode(NULL)
{
} //constructor

void Node::setNum(const int number)
{
	dataNumber = number; 
}

void Node::setNext(Node* nextNodePtr)
{
	nextNode = nextNodePtr;
}

int Node::getItem() const
{
	return dataNumber; 
}

Node* Node::getNext() const
{
	return nextNode; 
}
