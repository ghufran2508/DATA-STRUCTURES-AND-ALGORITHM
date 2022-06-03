#include<iostream>
#include"LinkedList.h"
#include"DLList.h"

using namespace std;

int main()
{
	DLList dl1, dl2;

	dl1.sortedInsert(5);
	dl1.sortedInsert(8);
	dl1.sortedInsert(20);

	dl2.sortedInsert(4);
	dl2.sortedInsert(11);
	dl2.sortedInsert(15);

	DLList result = dl1 + dl2;

	result.show();

	return 0;
}