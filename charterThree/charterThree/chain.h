#ifndef chain_
#define chain_

#include<iostream>
#include<sstream>
#include<string>
#include"linearList.h"
#include"chainNode.h"

#include"myExceptions.h"

using namespace std;

template<class T>
class chain : public linearList<T>
{
public:
	chain(int initialCapacity = 10);
	chain(const chain<T>&);
	~chain();
	bool empty() const { return listSize == 0; }
	int size() const { return listSize; }
	T& get(int theIndex) const;
	int indexOf(const T& theElement) const;
	void erase(int theIndex);
	void insert(int theIndex, const T& theElement);

	void output(ostream& out) const;
protected:
	void checkIndex(int theIndex) const;
	chainNode<T>* firstNode;
	int listSize;
};

template<class T>
chain<T>::chain(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << " the initialCapacity " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	firstNode = NULL;
	listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{// Copy constructor.
   listSize = theList.listSize;

   if (listSize == 0)
   {// theList is empty
      firstNode = NULL;
      return;
   }

   // non-empty list
   chainNode<T>* sourceNode = theList.firstNode;
                    // node in theList to copy from
   firstNode = new chainNode<T>(sourceNode->element);
                    // copy first element of theList
   sourceNode = sourceNode->next;
   chainNode<T>* targetNode = firstNode;
                    // current last node in *this
   while (sourceNode != NULL)
   {// copy remaining elements
      targetNode->next = new chainNode<T>(sourceNode->element);
      targetNode = targetNode->next;
      sourceNode = sourceNode->next;
   }
   targetNode->next = NULL; // end the chain
}

template<class T>
chain<T>::~chain()
{
	while (firstNode != NULL)
	{
		chainNode<T>* nextNode = firstNode->next;
		delete firstNode;
		firstNode = nextNode;
	}
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{
	if (theIndex < 0 || theIndex >= listSize)
	{
		ostringstream s;
		s << " the index = " << theIndex << " size = " << listSize;
		throw illegalIndex(s.str());
	}
}

template<class T>
T& chain<T>::get(int theIndex) const
{
	checkIndex(theIndex);
	chainNode<T>* theCurrent = firstNode;
	for (int i = 0; i < theIndex; ++i)
		theCurrent = theCurrent->next;
	return theCurrent->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{
	chainNode<T>* currentNode = firstNode;
	int count = 0;
	while (currentNode != NULL && currentNode->element != theElement)
	{
		currentNode = currentNode->next;
		++count;
	}
	if (currentNode == NULL)
		return -1;
	else
		return count;
}

template<class T>
void chain<T>::erase(int theIndex)
{
	checkIndex(theIndex);
	chainNode<T>* currentNode = firstNode;
	if (theIndex == 0)
	{
		firstNode = firstNode->next;
		delete currentNode;
	}
	else
	{
		for (int i = 0; i < theIndex-1; ++i)
			currentNode = currentNode->next;
		chainNode<T>* p = currentNode;
		p->next = currentNode->next->next;
		delete currentNode;
	}
	listSize--;
}
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
	if (theIndex < 0 || theIndex > listSize)
	{
		ostringstream s;
		s << "theIndex = " << theIndex << "the size = " << listSize;
		throw illegalIndex(s.str());
	}
	
	if (theIndex == 0)
		firstNode = new chainNode<T>(theElement, firstNode);
	else
	{
		chainNode<T>* p = firstNode;
		for (int i = 0; i < theIndex - 1; ++i)
			p = p->next;
		p->next = new chainNode<T>(theElement, p->next);
	}

	listSize++;
}




template<class T>
void chain<T>::output(ostream& out) const
{
	chainNode<T>* currentNode = firstNode;
	while (currentNode != NULL)
	{
		out << currentNode->element << " ";
		currentNode = currentNode->next;
	}
}

template<class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
	x.output(out);
	return out;
}

#endif