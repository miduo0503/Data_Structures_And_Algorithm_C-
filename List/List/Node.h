#ifndef Node_
#define Node_

template<class T>
struct Node
{
	T data;
	Node<T>* prev;
	Node<T>* next;
	Node() { }
	Node(T& data)
	{
		this->data = data;
	}
	Node(T& data, Node<T>* first, Node<T>* last)
	{
		this->data = data;
		this->prev = first;
		this->next = last;
	}
};



#endif