#ifndef iterator_
#define iterator_

#include"const_iterator.h"
#include"Node.h"
#include"list.h"

template<class T>
class iterator : public const_iterator<T>
{
public:
	typedef T* iterator;

	iterator() { }
	T& operator*() { return retrieve(); }
	const T& operator*() const { return const_iterator::operator*(); }
	iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	iterator& operator++(int)
	{
		iterator old = *this;
		++(*this);
		return old;
	}

protected:
	iterator(Node* p) : const_iterator(p) { }
	friend class list<T>;
};

#endif