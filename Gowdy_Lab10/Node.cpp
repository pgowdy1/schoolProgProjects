/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 10
*	Node.cpp
********************************************/
using namespace std;

Node::Node()
{
	key = -1337; 
	order = 0;  
} 

Node::Node(int value)
{
	key = value; 
	order = 0; 
}

void Node::levelOrder()
{
	if(key != -1337)
	{
		cout << key; 
	}
	
	if(siblingPtr != NULL)
	{
		siblingPtr->levelOrder();
	}

	else
	{
		cout << endl;
	}

	if(childPtr != NULL)
	{
		childPtr->levelOrder(); 
	}
}

void Node::cAppend(Node* firstNode)
{
	if(childPtr != NULL)
	{
		childPtr->sAppend(firstNode);
	}

	else
	{
		childPtr = firstNode; 
	}

	order = firstNode->order + 1;
}

void Node::sAppend(Node* firstNode)
{
	if(siblingPtr != NULL)
	{
		siblingPtr->sAppend(firstNode);
	}

	else
	{
		siblingPtr = firstNode;
	}
}
	
















		



