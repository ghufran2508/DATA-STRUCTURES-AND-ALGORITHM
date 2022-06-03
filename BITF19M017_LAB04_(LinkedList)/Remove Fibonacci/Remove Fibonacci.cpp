#include<iostream>
#include"DLL.h"

using namespace std;

bool isfibonacci(int value)
{
	int start = 1, newvalue = 0;

	while (newvalue <= value)
	{
		if (newvalue == value)
			return true;
		int temp = newvalue;
		newvalue += start;
		start = temp;
	}
	return false;
}

void remove(DLL& series)
{
	int value = 0, prevalue = 0;
	bool flag = false;
	for (int i = 0; i < series.getsize(); i++)
	{
		if (series.isEmpty()) return;
		value = series.remove(i);

		if (i == series.getsize() - 1) flag = true;

		if (!isfibonacci(value))
		{
			if (prevalue == 0)
				series.insertAtHead(value);
			else
			{
				series.insertAfter(prevalue, value);
			}
			prevalue = value;
		}
		else
		{
			i--;
		}
		if (flag) return;
	}
}

int main()
{
	DLL series;

	for (int i = 0; i < 100; i++)
	{
		series.append(i);
	}

	remove(series);
	cout << endl;
	series.show();

	return 0;
}