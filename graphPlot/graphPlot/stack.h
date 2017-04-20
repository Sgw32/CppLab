#ifndef STACK_H
#define STACK_H

#include "stdafx.h"

template <typename T>
struct Stack
{
	Node<T>* top;
};

template <typename T>
Stack<T> initStack();

template <typename T>
void push(Stack<T>& s, T value);
template <typename T>
bool pop_s(Stack<T> &s,T& value);
template <typename T>
void clear(Stack<T>& s);
template <typename T>
bool isEmpty(Stack<T>& s);

template <typename T>
Stack<T> initStack()
{
	Stack<T> s = {NULL};
	return s;
};

template <typename T>
void push(Stack<T>& s, T value)
{
	Node<T>* temp = new Node<T>();
	temp->value=value;
	temp->next=s.top;
	s.top=temp;
}

template <typename T>
bool pop_s(Stack<T> &s, T& value)
{
	bool result = false;
	if (s.top)
	{
		result = true;
		Node<T>* temp = s.top;
		s.top=s.top->next;
		value = temp->value;
		delete temp;
	}
	return result;
}

template <typename T>
void clear(Stack<T>& s)
{
	while(s.top)
	{
		Node<T>* tmp = s.top;
		s.top=s.top->next;
		delete tmp;
	}
}

template <typename T>
bool isEmpty(Stack<T>& s)
{
	return !s.top;
}
#endif
