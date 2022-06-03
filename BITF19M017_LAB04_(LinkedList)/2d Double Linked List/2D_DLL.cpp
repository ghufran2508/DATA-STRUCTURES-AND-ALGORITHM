#include<iostream>
#include"2D_DLL.h"

using namespace std;

DDLL::DDLL()
{
	this->size = 10;
	head = new DLL();

	DLL* temp = head;
	for (int i = 0; i < size - 1; i++)
	{
		DLL* newdll = new DLL();
		temp->next = newdll;
		newdll->prev = temp;
		temp = temp->next;
	}
}

DDLL::DDLL(int row, int col)
{
	this->size = (row > 0) ? row : 10;
	head = new DLL(col);

	DLL* temp = head;
	for (int i = 0; i < size - 1; i++)
	{
		DLL* newdll = new DLL(col);
		temp->next = newdll;
		newdll->prev = temp;
		temp = temp->next;
	}
}

DDLL::~DDLL()
{
	DLL* temp = head;

	while (head != NULL)
	{
		head = head->next;

		delete temp;
		temp = head;
	}
	head = NULL;
}

DDLL::DDLL(const DDLL& ref)
{
	this->size = ref.size;

	this->head = new DLL(ref.head->getSize());

	for (int i = 0; i < ref.head->getSize(); i++)
	{
		this->head->setAt(i, ref.head->getAt(i));
		if (ref.head->deleteStatus(i))
		{
			this->head->removeAt(i);
		}
	}
	DLL* temp = head;
	DLL* tempref = ref.head;

	for (int i = 0; i < size - 1; i++)
	{
		tempref = tempref->next;

		DLL* newdll = new DLL(tempref->getSize());

		temp->next = newdll;
		newdll->prev = temp;
		temp = temp->next;
		for (int j = 0; j < tempref->getSize(); j++)
		{
			temp->setAt(j, tempref->getAt(j));
			if (tempref->deleteStatus(i))
			{
				temp->removeAt(j);
			}
		}
	}
}

DDLL::DDLL(DDLL&& move)
{
	this->head = move.head;
	this->size = move.size;
	move.head = NULL;
	move.size = 0;
}

DDLL& DDLL::operator=(const DDLL& ref)
{
	if (this->head)
	{
		DLL* temp = head;

		while (head != NULL)
		{
			head = head->next;
			delete temp;
			temp = head;
		}
		head = NULL;
	}

	this->size = ref.size;

	this->head = new DLL(ref.head->getSize());

	for (int i = 0; i < ref.head->getSize(); i++)
	{
		this->head->setAt(i, ref.head->getAt(i));
		if (ref.head->deleteStatus(i))
		{
			this->head->removeAt(i);
		}
	}
	DLL* temp = head;
	DLL* tempref = ref.head;

	for (int i = 0; i < size - 1; i++)
	{
		tempref = tempref->next;

		DLL* newdll = new DLL(tempref->getSize());

		temp->next = newdll;
		newdll->prev = temp;
		temp = temp->next;
		for (int j = 0; j < tempref->getSize(); j++)
		{
			temp->setAt(j, tempref->getAt(j));
			if (tempref->deleteStatus(i))
			{
				temp->removeAt(j);
			}
		}
	}

	return *this;
}

DDLL& DDLL::operator=(DDLL&& move)
{
	if (head == move.head) return *this;
	this->head = move.head;
	this->size = move.size;
	move.head = NULL;
	move.size = 0;
	return *this;
}

void DDLL::print()
{
	DLL* temp = this->head;

	while (temp != NULL)
	{
		temp->print();
		temp = temp->next;
	}
	cout << endl;
}

int DDLL::getAt(int row, int c)
{
	if (row < 0 || row >= size) exit(0);

	DLL* tempr = this->head;

	for (int i = 0; i < row; i++)
	{
		tempr = tempr->next;
	}
	return tempr->getAt(c);
}

void DDLL::setAt(int row, int col, int value)
{
	if (row < 0 || row >= size) return;

	DLL* tempr = this->head;

	for (int i = 0; i < row; i++)
	{
		tempr = tempr->next;
	}
	tempr->setAt(col, value);
}

void DDLL::removeAt(int r, int c)
{
	if (r < 0 || r >= size) return;

	DLL* temp = head;

	for (int i = 0; i < r; i++)
	{
		temp = temp->next;
	}

	temp->removeAt(c);
}

bool DDLL::deleteStatus(int r, int c)
{
	if (r > 0 || r <= size) exit(0);

	DLL* temp = head;

	for (int i = 0; i < r; i++)
	{
		temp = temp->next;
	}

	return temp->deleteStatus(c);
}