#include<iostream>
#include"DLL.h"
#include"2D_DLL.h"

using namespace std;

int main()
{
	DDLL a, b; 
	DDLL c(5, 5);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			c.setAt(i, j, j * i);
			a.setAt(i * 2, j, i + j);
			b.setAt(i, j * 2, i - j + 3);
		}
	}
	cout << "A:" << endl;
	a.print();
	cout << "B:" << endl;
	b.print();
	cout << "C:" << endl;
	c.print();
	return 0;
}