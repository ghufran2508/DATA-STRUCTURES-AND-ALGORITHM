#pragma once

#ifndef DLL_H
#define DLL_H

#include"Node.h"

class DLL
{
	Node* head, * tail;
	int size;
public:
	DLL* next, *prev;
	DLL();
	DLL(int n);
	DLL(const DLL& ref);
	DLL(DLL&& move);
	~DLL();

	DLL& operator=(const DLL& ref);
	DLL& operator=(DLL&& move);

	int getSize() const;

	void print();

	void setAt(int n, int value);
	int getAt(int n);
	void removeAt(int n);
	bool deleteStatus(int n);
};

#endif // !DLL_H
