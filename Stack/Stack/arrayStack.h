#ifndef arrayStack_
#define arrayStack_

#include<sstream>
#include<string>
#include"stack.h"
#include"changeLength1D.h"
#include"myExceptions.h"

using namespace std;

template<class T>
class arrayStack : public stack<T>
{
public:
	arrayStack(int initialCapacity = 10);
	~arrayStack() { delete [] stack; }
	bool empty() const { return stackTop == -1; }
	int size() const { return stackTop; }
	T& top() const
	{
		if (stackTop == -1)
			throw stackEmpty();
		return stack[stackTop];
	}
	void pop()
	{
		if (stackTop == -1)
			throw stackEmpty();
		stack[--stackTop].~T();
	}
	void push(const T& theElement);
private:
	int stackTop;
	int arrayLength;
	T* stack;
};

template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
	if (initialCapacity < 1)
	{
		ostringstream s;
		s << " the initial = " << initialCapacity << " Must be > 0";
		throw illegalParameterValue(s.str());
	}
	arrayLength = initialCapacity;
	stack = new T[arrayLength];
	stackTop = -1;
}
template<class T>
void arrayStack<T>::push(const T& theElement)
{
	if (stackTop + 1 == arrayLength)
	{
		changeLength1D(stack, arrayLength, arrayLength * 2);
		arrayLength *= 2;
	}
	stack[++stackTop] = theElement;
}

#endif