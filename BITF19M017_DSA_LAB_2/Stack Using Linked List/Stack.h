#pragma once

#include<iostream>
#include<string>

using namespace std;

//node class using templates..
template<class type>
class node
{
	type data;	//data can be of any type
public:
	node<type>* next;

	node();
	node(type value);
	type getx();
};

//stack can be of any type. since its a template.
template<class type>
class stack
{
	node<type>* top;
public:
	stack();
	~stack();

	bool isEmpty();
	type pop();
	void push(type value);
	type seek();
};

template<class type>
node<type>::node()
{
	next = NULL;
}
//seeting the value and setting nect to NULL
template<class type>
node<type>::node(type value)
{
	data = value;
	next = NULL;
}

template<class type>
type node<type>::getx()
{
	return data;
}

template<class type>
stack<type>::stack()
{
	top = NULL;
}

template<class type>
stack<type>::~stack()
{
	//top would go down step by step and temp would store previous.
	//then the previous stack element would get deleted.
	node<type>* temp = top;

	while (top != NULL)
	{
		top = top->next;
		delete temp;
		temp = top;
	}
}

template<class type>
bool stack<type>::isEmpty()
{
	return (top == NULL);
}

template<class type>
void stack<type>::push(type value)
{
	node<type>* newtop = new node<type>(value);

	newtop->next = top;
	top = newtop;
}

template<class type>
type stack<type>::pop()
{
	if (isEmpty())
	{
		cout << "Stack is empty!!!" << endl;
		return 0;
	}
	else
	{
		type value = top->getx();
		top = top->next;
		return value;
	}
}

template<class type>
type stack<type>::seek()
{
	if (isEmpty())
	{
		cout << "Stack is empty!!!" << endl;
		return 0;
	}
	else
	{
		return top->getx();
	}
}