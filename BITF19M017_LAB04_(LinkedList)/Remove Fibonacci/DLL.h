#pragma once

#ifndef DLL_H
#define DLL_H

#include<iostream>

struct Node
{
	int data;
	Node* prev, * next;
	Node(int value)
	{
		this->data = value;
		prev = next = NULL;
	}
};

class DLL
{
	int size;
	Node* head, * tail;
public:
	DLL()
	{
		head = NULL;
		tail = NULL;
		size = 0;
	}
	void append(int value)
	{
		Node* temp = new Node(value);
		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}
	void insertAtHead(int value)
	{
		Node* temp = new Node(value);

		if (head == NULL)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			temp->next = head;
			head->prev = temp;
			head = temp;
		}
		size++;
	}
	int removeAtHead()
	{
		if (head == NULL) exit(0);

		Node* temp = head;
		int value = head->data;
		head = head->next;
		if (head == NULL) tail = NULL;
		delete temp;
		size--;
		return value;
	}
	Node* searchElement(int value)
	{
		Node* temp = head;

		while (temp != NULL && temp->data != value)
		{
			temp = temp->next;
		}

		return temp;
	}
	void sortedInsert(int data) {

		if (head == NULL)
		{
			insertAtHead(data);
			return;
		}

		Node* nodet = new Node(data);
		if (head->data > data)
		{
			nodet->next = head;
			head->prev = nodet;
			head = nodet;
		}
		else
		{
			Node* temp = head, * store = NULL;
			while (temp != NULL)
			{
				if (temp->data > data)
				{
					break;
				}

				store = temp;
				temp = temp->next;
			}
			if (temp == NULL)
			{
				store->next = nodet;
				nodet->prev = store;
			}
			else
			{
				nodet->prev = temp->prev;
				nodet->next = temp;
				temp->prev->next = nodet;
				temp->prev = nodet;
			}
		}
		size++;
	}

	void insertBefore(int value, int newvalue)
	{
		Node* temp = searchElement(value);

		if (temp == NULL)
			return;
		if (temp == head)
		{
			insertAtHead(newvalue);
			return;
		}
		else
		{
			Node* newtemp = new Node(newvalue);

			newtemp->next = temp;
			newtemp->prev = temp->prev;
			temp->prev->next = newtemp;
			temp->prev = newtemp;
		}
		size++;
	}
	void insertAfter(int value, int newvalue)
	{
		Node* temp = searchElement(value);

		if (temp == NULL)
			return;
		if (temp == tail)
		{
			append(newvalue);
		}
		else
		{
			Node* newtemp = new Node(newvalue);

			newtemp->prev = temp;
			newtemp->next = temp->next;
			temp->next->prev = newtemp;
			temp->next = newtemp;
		}
		size++;
	}
	int remove(int index)
	{
		if (head == NULL || index < 0)
		{
			exit(0);
		}
		else
		{
			Node* temp = head;
			if (index == 0)
			{
				if (head == tail)
				{
					head = tail = NULL;
				}
				else
				{
					head = head->next;
				}
			}
			else
			{
				for (int i = 0; i < index; i++)
				{
					if (temp == NULL) exit(0);

					temp = temp->next;
				}

				if (temp == NULL) exit(0);

				temp->prev->next = temp->next;
				if (temp->next != NULL)
				{
					temp->next->prev = temp->prev;
				}
				else
				{
					tail = tail->prev;
				}
			}

			int value = temp->data;
			size--;
			delete temp;
			return value;
		}
	}
	void show()
	{
		Node* temp = head;

		while (temp != NULL)
		{
			
			std::cout << temp->data << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	bool isEmpty()const
	{
		return (head == NULL);
	}
	int getsize() const
	{
		return this->size;
	}
	~DLL()
	{
		Node* temp;

		while (head != NULL)
		{
			temp = head;
			head = head->next;

			delete temp;
		}
	}
};

#endif // !DLL_H
