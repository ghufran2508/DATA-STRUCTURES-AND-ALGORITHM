#pragma once

#ifndef LINKLIST_H
#define LINKLIST_H

#include<iostream>
#include<string>

using namespace std;

struct Node
{
	string data;
	Node* next;
	Node(string value)
	{
		data = value;
		next = NULL;
	}
};
class LinkList
{
	Node* head;
public:
	LinkList()
	{
		head = NULL;
	}
	LinkList(const LinkList& ref)
	{
		if (ref.head != NULL)
		{
			head = new Node(ref.head->data);

			Node* tempref = ref.head;
			Node* temp = head;

			tempref = tempref->next;

			while (tempref != NULL)
			{
				temp->next = new Node(tempref->data);
				tempref = tempref->next;
				temp = temp->next;
			}
		}
		else
		{
			head = NULL;
		}
	}
	void insertAtHead(string value)
	{
		Node* newnode = new Node(value);
		newnode->next = head;
		head = newnode;
	}
	void insertAtTail(string value)
	{
		if (head == NULL)
		{
			head = new Node(value);
		}
		else
		{
			Node* temp = head;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new Node(value);
		}
	}
	string RemoveAtHead(void)
	{
		if (head == NULL)
		{
			exit(0);
		}

		string value = head->data;
		Node* temp = head;
		head = head->next;
		delete temp;
		return value;
	}
	string RemoveAtTail(void)
	{
		if (head == NULL)
		{
			exit(0);
		}
		else if (head->next == NULL)
		{
			string value = head->data;
			delete head;
			head = NULL;
			return value;
		}
		else
		{
			Node* temp = head, * store = NULL;

			while (temp->next != NULL)
			{
				store = temp;
				temp = temp->next;
			}
			string value = temp->data;
			store->next = NULL;
			delete temp;
			return value;
		}
	}
	void insertAtIndex(int index, string val)
	{
		if (head == NULL)
		{
			exit(0);
		}
		else
		{
			Node* temp = head;
			for (int i = 0; i < index; i++)
			{
				if (temp == NULL)	exit(0);

				temp = temp->next;
			}
			if (temp == NULL) exit(0);

			temp->data = val;
		}
	}
	string removeAtIndex(int index)
	{
		if (head == NULL)
		{
			exit(0);
		}
		else
		{
			Node* temp = head;
			if (index == 0)
			{
				head = head->next;
			}
			else
			{
				Node* store = NULL;

				for (int i = 0; i < index; i++)
				{
					if (temp == NULL)
						exit(0);
					store = temp;
					temp = temp->next;
				}

				store->next = temp->next;
			}

			string value = temp->data;
			delete temp;
			return value;
		}
	}
	void insertBefore(int index, string val)
	{
		Node* newnode = new Node(val);
		if (index == 0)
		{
			newnode->next = head;
			head = newnode;
		}
		else
		{
			Node* temp = head, * store = NULL;
			for (int i = 0; i < index; i++)
			{
				if (temp == NULL) exit(0);

				store = temp;
				temp = temp->next;
			}
			if (temp == NULL) exit(0);

			store->next = newnode;
			newnode->next = temp;
		}
	}
	string removeBefore(int index)
	{
		if (head == NULL || index == 0)
		{
			exit(0);
		}
		else
		{
			Node* temp = head;
			if (index == 1)
			{
				head = head->next;
			}
			else
			{
				Node* temp = head, * store = NULL;

				for (int i = 0; i < index - 1; i++)
				{
					if (temp == NULL)	exit(0);

					store = temp;
					temp = temp->next;
				}

				if (temp == NULL)	exit(0);

				store->next = temp->next;
			}
			string value = temp->data;
			delete temp;
			return value;
		}
	}
	void insertAfter(int index, string val)
	{
		Node* newnode = new Node(val);

		if (head == NULL)
		{
			head = newnode;
		}
		else
		{
			Node* temp = head, * store = NULL;

			for (int i = 0; i < index + 1; i++)
			{
				if (temp == NULL) exit(0);

				store = temp;
				temp = temp->next;
			}
			if (store == NULL) exit(0);

			store->next = newnode;
			newnode->next = temp;
		}
	}
	string removeAfter(int index)
	{
		if (head == NULL)
		{
			exit(0);
		}
		else
		{
			Node* temp = head, * store = NULL;

			for (int i = 0; i < index + 1; i++)
			{
				if (temp == NULL) exit(0);

				store = temp;
				temp = temp->next;
			}

			if (temp == NULL) exit(0);

			string value = temp->data;
			store->next = temp->next;
			delete temp;
			return value;
		}
	}
	string getIndexValue(int index)
	{
		if (head == NULL) exit(0);

		Node* temp = head;

		for (int i = 0; i < index; i++)
		{
			if (temp == NULL) exit(0);

			temp = temp->next;
		}
		if (temp == NULL) exit(0);

		return temp->data;
	}
	string& operator[](int index)
	{
		if (head == NULL) exit(0);

		Node* temp = head;

		for (int i = 0; i < index; i++)
		{
			if (temp == NULL) exit(0);

			temp = temp->next;
		}
		if (temp == NULL) exit(0);

		return temp->data;
	}
	LinkList& operator=(const LinkList& ref)
	{
		if (head != NULL)
		{
			Node* temp = head;

			while (head != NULL)
			{
				temp = head;
				head = head->next;

				delete temp;
			}
		}

		if (ref.head != NULL)
		{
			head = new Node(ref.head->data);
		}

		Node* tempref = ref.head;
		Node* temp = head;

		tempref = tempref->next;

		while (tempref != NULL)
		{
			temp->next = new Node(tempref->data);
			tempref = tempref->next;
			temp = temp->next;
		}

		return *this;
	}
	bool isEmpty()
	{
		return (head == NULL);
	}
	~LinkList()
	{
		Node* temp = head;

		while (head != NULL)
		{
			temp = head;
			head = head->next;

			delete temp;
		}
	}
};

#endif