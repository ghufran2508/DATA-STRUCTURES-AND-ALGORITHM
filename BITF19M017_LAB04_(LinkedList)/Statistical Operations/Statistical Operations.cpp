#include<iostream>
#include<fstream>
#include"DLL.h"

using namespace std;

int main()
{
	ifstream input;
	input.open("data.txt");

	int data;

	if (input.fail())
	{
		cout << "Fail to locate file!!!" << endl;
		exit(0);
	}
	else
	{
		DLList mylist;

		while (!input.eof())
		{
			input >> data;
			mylist.sortedInsert(data);
		}
		mylist.show();
		cout << "Mean = " << mylist.mean() << endl;
		cout << "Median = " << mylist.median() << endl;
		cout << "Mode = " << mylist.mode() << endl;
		cout << "Standard Deviation = " << mylist.standardDeviation() << endl;
		cout << "Variance = " << mylist.variance() << endl;
	}

	return 0;
}