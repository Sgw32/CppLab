#ifndef NODE_H
#define NODE_H

template <typename T> 
struct Node
{
	Node<T>* next;
	T value;
};

#endif