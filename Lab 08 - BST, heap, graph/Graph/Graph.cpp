#include<iostream>
#include"Graph.h"

using namespace std;

int main()
{
	Course a;
	a.addCourse("PF", 3);

	Course b;
	b.addCourse("OOP", 3);

	Course c;
	c.addCourse("DSA", 3);

	Graph PUCIT;

	PUCIT.InsertVertex(&a);
	PUCIT.InsertVertex(&b);
	PUCIT.InsertVertex(&c);
	
	PUCIT.InsertPair(a, b);
	PUCIT.InsertPair(b, c);

	PUCIT.InOrderTraversal();

	PUCIT.DFS();

	return 0;
}