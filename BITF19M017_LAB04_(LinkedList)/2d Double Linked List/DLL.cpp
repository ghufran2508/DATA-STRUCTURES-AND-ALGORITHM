#include<iostream>
#include"DLL.h"

using namespace std;

DLL::DLL()
{
	this->next = NULL;
	this->prev = NULL;
	this->size = 10;
	head = new Node(0);
	tail = head;

	for (int i = 0; i < size - 1; i++)
	{
		tail->setStatus(true);
		Node* temp = new Node(0);
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
	}
	tail->setStatus(true);
}

DLL::DLL(int n)
{
	this->next = NULL;
	this->prev = NULL;
	this->size = (n > 0) ? n : 10;
	head = new Node(0);
	tail = head;

	for (int i = 0; i < size - 1; i++)
	{
		tail->setStatus(true);
		Node* temp = new Node(0);
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
	}
	tail->setStatus(true);
}

DLL::DLL(const DLL& ref)
{
	this->next = ref.next;
	this->prev = NULL;
	this->size = ref.size;
	head = new Node(ref.head->getData());
	tail = head;
	Node* tempref = ref.head;

	for (int i = 0; i < size - 1; i++)
	{
		tail->setStatus(tempref->getStatus());
		tempref = tempref->next;
		Node* temp = new Node(tempref->getData());
		tail->next = temp;
		temp->prev = tail;
		tail = tail->next;
	}
	tail->setStatus(tempref->getStatus());
}

DLL& DLL::operator=(const DLL& ref)
{
	this->next = ref.next;
	this->prev = ref.prev;
	this->size = ref.size;

	if (this->head)
	{
		Node* temp = head;

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
		head = new Node(ref.head->getData());
		tail = head;
		Node* tempref = ref.head;

		for (int i = 0; i < size - 1; i++)
		{
			tail->setStatus(tempref->getStatus());
			tempref = tempref->next;
			Node* temp = new Node(tempref->getData());
			tail->next = temp;
			temp->prev = tail;
			tail = tail->next;
		}
		tail->setStatus(tempref->getStatus());
	}

	return *this;
}

DLL::DLL(DLL&& move)
{
	this->next = move.next;
	this->prev = move.prev;
	this->size = move.size;
	this->head = move.head;
	this->tail = move.tail;
	move.size = 0;
	move.head = move.tail = NULL;
	move.next = move.prev = NULL;
}

DLL& DLL::operator=(DLL&& move)
{
	if (this->head == move.head) return *this;
	this->next = move.next;
	this->prev = move.prev;
	this->size = move.size;
	this->head = move.head;
	this->tail = move.tail;
	move.size = 0;
	move.head = NULL;
	move.tail = NULL;
	move.next = NULL;
	move.prev = NULL;
	return *this;
}

DLL::~DLL()
{
	Node* temp = head;

	while (head != NULL)
	{
		head = head->next;

		delete temp;
		temp = head;
	}
	head = tail = NULL;
}

void DLL::print()
{
	Node* temp = head;

	while (temp != NULL)
	{
		if(temp->getStatus() == false)
			cout << temp->getData() << " ";
		temp = temp->next;
	}
	cout << endl;
}

int DLL::getSize()const
{
	return this->size;
}

void DLL::setAt(int n, int value)
{
	if (n < 0 || n >= size)
	{
		cout << "Out of index!!!" << endl;
		return;
	}
	else
	{
		Node* temp = head;

		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}
		temp->setData(value);
		temp->setStatus(false);
	}
}

int DLL::getAt(int n)
{
	if (n < 0 || n >= size)
	{
		exit(0);
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}
		if (temp->getStatus() == false)
			return temp->getData();
		else
			return 0;
	}
}

void DLL::removeAt(int n)
{
	if (n < 0 || n >= size)
	{
		return;
	}
	else
	{
		Node* temp = head;

		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}

		temp->setStatus(true);
	}
}

bool DLL::deleteStatus(int n)
{
	if (n < 0 || n >= size)
	{
		exit(0);
	}
	else
	{
		Node* temp = head;

		for (int i = 0; i < n; i++)
		{
			temp = temp->next;
		}

		return temp->getStatus();
	}
}