#pragma once

#ifndef NODE_H
#define NODE_H

#include<iostream>

class Node
{
	int data;
	bool delete_status;
public:
	Node* prev, * next;
	Node(int value)
	{
		this->data = value;
		prev = next = NULL;
		delete_status = false;
	}
	void setData(int value)
	{
		this->data = value;
	}
	int getData() const
	{
		return this->data;
	}
	void setStatus(bool status)
	{
		delete_status = status;
	}
	bool getStatus() const
	{
		return this->delete_status;
	}
};

#endif // !NODE_H
