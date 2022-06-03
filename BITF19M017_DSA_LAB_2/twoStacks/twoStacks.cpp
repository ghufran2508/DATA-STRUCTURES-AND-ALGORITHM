#include<iostream>
#include"twoStacks.h"

using namespace std;

int main()
{
	TwoStack my2(10);
	int num;

	//storing stack1 elements at even indexes like 0,2,4,6....
	//storing stack2 elements at odd indexes like 1,3,5,7....
	//1 array but 2 stacks.
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter stack1 element: ";
		cin >> num;
		my2.push1(num);
		cout << "Enter stack2 element: ";
		cin >> num;
		my2.push2(num);
	}

	cout << "stack1 elements: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << my2.pop1() << endl;
	}
	cout << "stack2 elements: " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << my2.pop2() << endl;
	}

	return 0;
}