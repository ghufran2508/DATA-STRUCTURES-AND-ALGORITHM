#pragma once

#ifndef D_DLL_H
#define D_DLL_H

#include"DLL.h"

class DDLL
{
	DLL* head;
	int size;
public:
	DDLL();
	DDLL(int r, int c);

	~DDLL();

	DDLL(const DDLL& ref);
	DDLL(DDLL&& ref);

	DDLL& operator=(const DDLL& ref);
	DDLL& operator=(DDLL&& ref);

	void print();

	int getAt(int r, int c);
	void setAt(int r, int c, int value);

	void removeAt(int r, int c);
	bool deleteStatus(int r, int c);
};

#endif // !2D_DLL_H
