#ifndef Vector_
#define Vector_

#include<iostream>
#include<algorithm>
using namespace std;

template<class T>
class Vector
{
public:
	Vector(int initSize = 0) :
		theSize(initSize), theCapacity(initSize + SPARE_CAPACITY)
	{ 
		objects = new T[theSize];

	}

	Vector(const Vector<T>& theVec) :objects(NULL)
	{ operator=(theVec); }

	~Vector()
	{ delete[] objects; }

	const Vector<T>& operator=(const Vector<T>& theVec)
	{
		if (this != &theVec)
		{
			delete [] objects;
			theSize = theVec.theSize;
			theCapacity = theVec.theCapacity;

			objects = new T[theCapacity];
			for (int i = 0; i < theSize; ++i)
				objects[i] = theVec.objects[i];
		}
		return *this;
	}

	void resize(int newSize)
	{
		if (newSize > theSize)
			reverse(newSize * 2 + 1);
		theSize = newSize;
	}

	void reverse(int newCapacity)
	{
		if (newCapacity < theCapacity)
			return;
		T* oldArray = objects;
		objects = new T[newCapacity];
		for (int i = 0; i < theSize; ++i)
			objects[i] = oldArray[i];

		theCapacity = newCapacity;

		delete[] oldArray;
	}

	T& operator[](int index)
	{ return objects[index]; }

	const T& operator[](int index) const
	{ return objects[index]; }

	bool empty() const { return theSize == 0; }
	int size() const { return theSize; }
	int capacity() const { return theCapacity; }

	void push_back(T theElement)
	{
		if (theSize == theCapacity)
			reverse(theSize * 2 + 1);
		objects[theSize++] = theElement;
	}

	void pop_back() { theSize--; }

	const T& back() const
	{
		return objects[theSize - 1];
	}

	typedef T* iterator;
	typedef const T* const_iterator;

	iterator begin()
	{ return &objects[0]; }
	const_iterator begin() const
	{
		return &objects[0];
	}

	iterator end()
	{
		return &objects[theSize - 1];
	}
	const_iterator end() const
	{
		return &objects[theSize - 1];
	}

	void output(ostream& out) const
	{
		copy(objects, objects + theSize, ostream_iterator<T>(cout, " "));
	}


	enum{ SPARE_CAPACITY = 16 };

private:
	int theSize;
	int theCapacity;
	T* objects;
};

template<class T>
ostream& operator<<(ostream& out, Vector<T>& x)
{ 
	x.output(out);
	return out;
}

#endif