#ifndef const_iterator_
#define const_iterator_

#include"Node.h"
#include"list.h"

template<class T>
class const_iterator
{
public:
	typedef const T* const_iterator;

	const_iterator() :current(NULL)
	{ }
	const T& operator*()const { return retrieve(); }
	const_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	const_iterator& operator++(int)
	{
		const_iterator old = *this;
		++(*this);
		return old;
	}
	bool operator==(const const_iterator& rhs) const
	{
		return currrent == rhs.current;
	}
	bool operator!=(const const_iterator& rhs) const
	{
		return !(*this == rhs);
	}

protected:
	Node* current;
	T& retrieve() const
	{
		return current->data;
	}
	const_iterator(Node* p) : current(p)
	{ }
	friend class List<T>;
}; 

#endif