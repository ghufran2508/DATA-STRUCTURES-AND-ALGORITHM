#include<iostream>
#include"Min_heap.h"

using namespace std;

int main()
{
	MinHeap mh;

	Employee emp1("A", "a", 33, 11,11,2003);
	Employee emp2("B", "b", 31, 05,8,2001);
	Employee emp3("C", "c", 40, 12,01,2004);
	Employee emp4("D", "d", 41, 31,05,2010);
	Employee emp5("E", "e", 21, 25,8,2000);

	mh.Insert(emp1);
	mh.Insert(emp2);
	mh.Insert(emp3);
	mh.Insert(emp4);
	mh.Insert(emp5);

	cout << mh.getMostSenior();
	mh.RemoveMostSenior();

	cout << mh.getMostSenior();
	mh.RemoveMostSenior();

	cout << mh.getMostSenior();
	mh.RemoveMostSenior();

	cout << mh.getMostSenior();
	mh.RemoveMostSenior();

	cout << mh.getMostSenior();
	mh.RemoveMostSenior();

	return 0;
}