#include<iostream>
#include"DLList.h"

using namespace std;

int main()
{
	DLList dl;

	dl.append(1);
	dl.append(2);
	dl.append(3);
	dl.append(4);
	dl.append(5);
	dl.append(6);
	dl.append(1);
	dl.append(2);
	dl.append(3);
	dl.append(4);
	dl.append(5);
	dl.append(6);

	dl.show();
	DLList d2;
	d2 = d2.modify(dl, 3);
	d2.show();

	return 0;
}
