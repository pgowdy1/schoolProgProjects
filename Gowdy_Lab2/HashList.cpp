/********************************************
*	Perry Gowdy
*	EECS 560
*	LAB 2
*	HashList.h
********************************************/

HashList::HashList() : nextPtr(NULL)
{
}

HashList::HashList(int number) : nextPtr(NULL)
{ 
	value = number; 
}

int HashList::getValue()
{
	return value;
}

void HashList::setValue(int number)
{
	value = number; 
}

HashList* HashList::getNext()
{
	return nextPtr; 
}

void HashList::setNext(HashList* ptr)
{
	nextPtr = ptr; 
}

