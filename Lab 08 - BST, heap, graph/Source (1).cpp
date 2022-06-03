#include<iostream>
#include"BST.h"
using namespace std;

int main()
{
	BST<int> a;
	a.insert(1);
	a.insert(2);
	a.insert(3);
	a.insert(33);
	a.insert(43);
	a.insert(5);
	a.insert(24);
	a.insert(14);
	a.insert(10);
	a.insert(27);
	a.printInOrder();
	a.remove(22);
	a.printInOrder();
	a.replace(10, 13);
	a.printInOrder();
	a.printLevelOrder(2);
	return 0;
}

