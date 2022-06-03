#pragma once

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include<iostream>
#include<string>
#include"Date.h"

using namespace std;

class Employee { // 10 marks
	string first_name;
	string last_name;
	int age;
	Date date_of_joining;
public:
	Employee() :date_of_joining()
	{
		first_name = "NULL";
		last_name = "NULL";
		age = 1;
	}
	Employee(string first_name, string last_name, int age, int date, int month, int year): date_of_joining(date,month,year)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->age = (age > 18 && age <= 65) ? age : 19;
	}
	Employee(string first_name, string last_name, int age, Date doj) :date_of_joining(doj)
	{
		this->first_name = first_name;
		this->last_name = last_name;
		this->age = (age > 18 && age <= 65) ? age : 19;
	}

	void setFirstName(string first_name)
	{
		this->first_name = first_name;
	}
	void setLastName(string last_name)
	{
		this->last_name = last_name;
	}
	void setAge(int age)
	{
		this->age = (age > 18 && age <= 65) ? age : 19;
	}

	string getFirstName() const
	{
		return this->first_name;
	}
	string getLastName() const
	{
		return this->last_name;
	}
	int getAge() const
	{
		return this->age;
	}
	Date getDate() const
	{
		return this->date_of_joining;
	}

	bool operator<(const Employee& ref) const
	{
		return this->date_of_joining < ref.date_of_joining;
	}
	bool operator<=(const Employee& ref) const
	{
		return this->date_of_joining <= ref.date_of_joining;
	}
	bool operator>(const Employee& ref) const
	{
		return this->date_of_joining > ref.date_of_joining;
	}
	bool operator>=(const Employee& ref) const
	{
		return this->date_of_joining >= ref.date_of_joining;
	}
	bool operator==(const Employee& ref) const
	{
		return this->date_of_joining == ref.date_of_joining;
	}
	bool operator!=(const Employee& ref) const
	{
		return this->date_of_joining != ref.date_of_joining;
	}

	friend ostream& operator<<(ostream&, const Employee& ref);
};

ostream& operator<<(ostream& out, const Employee& ref)
{
	out << "\n**************************************************\n";
	out << "First Name = " << ref.first_name << endl;
	out << "Last Name = " << ref.last_name << endl;
	out << "Age = " << ref.age << endl;
	out << "Date Of Joining = " << ref.date_of_joining << endl;
	out << "\n**************************************************\n";

	return out;
}

#endif // !EMPLOYEE_H
