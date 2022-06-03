#pragma once
#ifndef DLL_H
#define DLL_H

#include<iostream>
#include"Node.h"

using namespace std;

class DLList
{
	node* head, * tail;
public:
	DLList()
	{
		head = NULL;
		tail = NULL;
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
	void append(int value)
	{
		node* found = searchElement(value);
		if (found == NULL)
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
		else
		{
			found->setFrequency(found->getFreq() + 1);
		}
	}
	void sortedInsert(int data) {

		node* found = searchElement(data);

		if (found == NULL)
		{
			node* nodet = new node(data);
			if (head == NULL)
			{
				head = nodet;
				tail = head;
			}
			else if (head->getData() > data)
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
		else
		{
			found->setFrequency(found->getFreq() + 1);
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

			if (temp->getFreq() == 1)
				delete temp;
			else
				temp->setFrequency(temp->getFreq() - 1);

			return value;
		}
	}
	void show()
	{
		node* temp = head;

		while (temp != NULL)
		{
			for(int i = 0; i < temp->getFreq(); i++)
			{
				std::cout << temp->getData() << std::endl;
			}
			temp = temp->next;
		}
	}

	int totalFreq()
	{
		node* temp = head;
		int sum = 0;

		while (temp != NULL)
		{
			sum += temp->getFreq();
			temp = temp->next;
		}
		return sum;
	}

	int mean()
	{
		int sum = 0, values = totalFreq();

		node* temp = head;

		while (temp != NULL)
		{	
			sum += temp->getData()*temp->getFreq();
			temp = temp->next;
		}

		return sum/values;
	}

	int median()
	{
		int total = totalFreq();
		int count = 0, check = 0;

		if (total % 2 == 0)
			count = total / 2 - 1;
		else
			count = total / 2;

		node* temp = head;

		while (temp != NULL)
		{
			for (int i = 0; i < temp->getFreq(); i++)
			{
				check++;
				if (check == count) return temp->getData();
			}
			temp = temp->next;
		}
		return 0;
	}

	int mode()
	{
		int max = 0, value = 0;

		node* temp = head;

		while (temp != NULL)
		{
			if (temp->getFreq() > max)
			{
				max = temp->getFreq();
				value = temp->getData();
			}

			temp = temp->next;
		}
		return value;
	}

	int variance()
	{
		int sum = 0, tempo = 0;;
		int meanvalue = mean();
		node* temp = this->head;

		while (temp != NULL)
		{
			for (int i = 0; i < temp->getFreq(); i++)
			{
				tempo = (temp->getData() - meanvalue);
				tempo = tempo * tempo;
				sum += tempo;
			}
			temp = temp->next;
		}

		return sum / totalFreq();
	}

	int standardDeviation()
	{
		return sqrt(variance());
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


#endif // !DLL_H
