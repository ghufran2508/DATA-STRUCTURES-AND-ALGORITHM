#include<iostream>
#include<string>

using namespace std;

string Comma(long int number)
{
	if (number <= 999) return to_string(number);

	string str;
	int rem = number % 1000;

	str = to_string(rem);
	str = str.substr(str.size()-3,str.size());
	str = "," + str;

	return Comma(number / 1000) + str;
}

int main()
{
	long int num;

	cout << "Enter any positive number: ";
	cin >> num;

	while (num <= 0)
	{
		cout << "Please enter any positive number: ";
		cin >> num;
	}

	string str = Comma(num);
	//num = 1234567
	//return string 1,234,567

	cout << "String with commas in the appropriate places: " << str << endl;

	return 0;
}