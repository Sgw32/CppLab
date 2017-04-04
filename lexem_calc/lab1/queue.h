#ifndef QUEUE_H
#define QUEUE_H

#include "stdafx.h"

template <typename T>
struct Queue
{
	Node<T>* start;
	Node<T>* end;
};

template <typename T>
Queue<T> initQueue();

template <typename T>
void push(Queue<T>& s, T value);
template <typename T>
void pop(Queue<T>& s,T& value);
template <typename T>
void clear(Queue<T>& s);
template <typename T>
bool isEmpty(Queue<T>& s);

template <typename T>
Queue<T> initQueue()
{
	Queue<T> s = {NULL};
	return s;
};

template <typename T>
void push(Queue<T>& s, T value)
{
	Node<T>* temp = new Node<T>();
	temp->value=value;
	
	if (!s.start)
	{
		s.start=temp;
	}
	else
	{
		if (!s.end)
		{
			s.end=temp;
			s.start->next=s.end;
		}
		else
		{
			s.end->next=temp;
			s.end=temp;
		}
	}
}

template <typename T>
bool pop_s(Queue<T>& s, T& value)
{
	bool result = false;
	if (s.start)
	{
		result = true;
		Node<T>* temp = s.start;
		s.start=s.start->next;
		value = temp->value;
		delete temp;
	}
	return result;
}

template <typename T>
void clear(Queue<T>& s)
{
	while(s.start)
	{
		Node<T>* tmp = s.start;
		s.start=s.start->next;
		delete tmp;
	}
}

template <typename T>
bool isEmpty(Queue<T>& s)
{
	return !s.start;
}



#endif