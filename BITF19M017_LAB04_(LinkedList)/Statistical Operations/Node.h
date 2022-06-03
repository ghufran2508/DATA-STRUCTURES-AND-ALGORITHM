#pragma once

#ifndef NODE_H
#define NODE_H

#include<iostream>

class node
{
	int data;
	int frequency;
public:
	node* next, * prev;
	node(int value)
	{
		this->data = value;
		this->frequency = 1;
		next = NULL;
		prev = NULL;
	}
	int getData() const
	{
		return data;
	}
	void setFrequency(int freq)
	{
		this->frequency = (freq > 1) ? freq : 1;
	}
	int getFreq() const
	{
		return this->frequency;
	}
};

#endif // !NODE_H
