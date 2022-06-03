#pragma once

#ifndef DLLIST_H
#define DLLIST_H

#include<iostream>

class node
{
	int data;
public:
	node* next, * prev;
	node()
	{
		next = NULL;
		prev = NULL;
	}
	node(int value)
	{
		this->prev = NULL;
		this->data = value;
		this->next = NULL;
	}
	int getData()
	{
		return this->data;
	}
};

class DLList
{
	node* head, * tail;
public:
	DLList()
	{
		head = NULL;
		tail = NULL;
	}
	DLList(const DLList& ref)
	{
		if (ref.head != NULL)
		{
			head = new node(ref.head->getData());
			tail = head;

			node* temp = ref.head->next;

			while (temp != NULL)
			{
				node* newnode = new node(temp->getData());
				tail->next = newnode;
				newnode->prev = tail;
				temp = temp->next;
				tail = tail->next;
			}
		}
		else
		{
			head = tail = NULL;
		}
	}
	bool isEmpty() const
	{
		return (head == NULL);
	}
	DLList& operator=(const DLList& ref)
	{
		if (this->head)
		{
			node* temp = head;

			while (head != NULL)
			{
				head = head->next;

				delete temp;
				temp = head;
			}

			head = tail = NULL;
		}

		if (ref.head != NULL)
		{
			head = new node(ref.head->getData());
			tail = head;

			node* temp = ref.head->next;

			while (temp != NULL)
			{
				node* newnode = new node(temp->getData());
				tail->next = newnode;
				newnode->prev = tail;
				temp = temp->next;
				tail = tail->next;
			}
		}
		return *this;
	}
	void append(int value)
	{
		node* temp = new node(value);
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
	}
	void insertAtHead(int value)
	{
		node* temp = new node(value);

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
	}
	node* searchElement(int value)
	{
		node* temp = head;

		while (temp != NULL && temp->getData() != value)
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

		node* nodet = new node(data);
		if (head->getData() > data)
		{
			nodet->next = head;
			head->prev = nodet;
			head = nodet;
		}
		else
		{
			node* temp = head, * store = NULL;
			while (temp != NULL)
			{
				if (temp->getData() > data)
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
	}

	void insertBefore(int value, int newvalue)
	{
		node* temp = searchElement(value);

		if (temp == NULL)
			return;
		if (temp == head)
		{
			insertAtHead(newvalue);
			return;
		}
		else
		{
			node* newtemp = new node(newvalue);

			newtemp->next = temp;
			newtemp->prev = temp->prev;
			temp->prev->next = newtemp;
			temp->prev = newtemp;
		}
	}
	void insertAfter(int value, int newvalue)
	{
		node* temp = searchElement(value);

		if (temp == NULL)
			return;
		if (temp == tail)
		{
			append(newvalue);
		}
		else
		{
			node* newtemp = new node(newvalue);

			newtemp->prev = temp;
			newtemp->next = temp->next;
			temp->next->prev = newtemp;
			temp->next = newtemp;
		}
	}
	int remove(int index)
	{
		if (head == NULL || index < 0)
		{
			exit(0);
		}
		else
		{
			node* temp = head;
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
				temp->next->prev = temp->prev;
			}

			int value = temp->getData();

			delete temp;
			return value;
		}
	}
	void show()
	{
		node* temp = head;

		while (temp != NULL)
		{
			std::cout << temp->getData() << " ";
			temp = temp->next;
		}
		std::cout << std::endl;
	}
	DLList modify(const DLList& ref, int k)
	{
		DLList modified;
		node* temp = ref.head;

		while (temp != NULL)
		{
			for (int i = 0; i < k-1; i++)
			{
				if (temp->next == NULL) break;
				temp = temp->next;
			}
			node* rev = temp;
			temp = temp->next;
			for (int i = 0; i < k; i++)
			{
				modified.append(rev->getData());
				rev = rev->prev;
			}
		}
		return modified;
	}
	~DLList()
	{
		node* temp;

		while (head != NULL)
		{
			temp = head;
			head = head->next;

			delete temp;
		}
	}
};

#endif // !DLLIST_H
