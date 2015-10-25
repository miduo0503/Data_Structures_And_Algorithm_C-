#ifndef list_
#define list_

#include"Node.h"
#include"const_iterator.h"
#include"iterator.h"

typedef T* iterator;
typedef const T* const_iterator;

template<class T>
class list
{
public:
	list();
	list(int initialCapacity = 10);
	list(const list<T>&);
	~list();
	const list& operator=(const list<T>&);
	iterator begin() { return iterator(head->next); }
	const_iterator begin() { return const_iterator(head->next); }
	iterator end() { return iterator(tail);}
	const_iterator end() { return const_iterator(tail); }

	int size() const { return theSize; }
	bool empty() const { return theSize == 0; }
	void clear()
	{
		while (!empty())
			pop_front();
	}

	T& front() { return *begin(); }
	const T& front() const { return *begin(); }
	T& back() { return *--end(); }
	const T& back() const { return *--end(); }
	 
	void push_front(const T& x){ insert(begin(), x); }
	void push_back(const T& x) { insert(end(), x); }
	void pop_front() { erase(begin()); }
	void pop_back() { erase(--end()); }

	iterator insert(iterator iter, const T& x);
	iterator erase(iterator start, iterator end);

private:
	int theSize;
	Node* head;
	Node* tail;

	void init();
};

template<class T>
list<T>::list()
{
	init();
}
template<class T>
list<T>::~list()
{
	clear();
	delete head;
	delete tail;
}
template<class T>
list<T>::list(const list<T>& rhs)
{
	init();
	*this = rhs;
}

template<class T>
const list<T>& list<T>::operator=(const list<T>& rhs)
{
	if (this == &rhs)
		return *this;
	clear();
	for (const_iterator iter = rhs.begin(); iter != rhs.end(); ++iter)
		push_back(*iter);
	return *this;
}

template<class T>
void list<T>::init()
{
	theSize = 0;
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
}


#endif