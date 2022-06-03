#include<iostream>
#include<string>
#include"Stack.h"

using namespace std;

int main()
{
	stack<string> mys;

	mys.push("This ");
	mys.push("is a ");
	mys.push("test ");
	mys.push("string.");

	cout << mys.pop() << endl;
	cout << mys.pop() << endl;
	cout << mys.pop() << endl;
	cout << mys.pop() << endl;

	return 0;
}