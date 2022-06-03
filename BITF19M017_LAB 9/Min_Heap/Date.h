#pragma once

#ifndef DATE_H
#define DATE_H

#include<iostream>
using namespace std;

const int month_days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Date { // 10 - marks
	int month;
	int day;
	int year;
public:
	Date()
	{
		this->day = 1;
		this->month = 1;
		this->year = 1960;
	}
	Date(int d, int m, int y)
	{
		this->month = (m > 0 && m < 13) ? m : 1;
		if (d > 0 && d <= month_days[m-1])
		{
			this->day = d;
		}
		else
			this->day = 1;

		this->year = (y >= 1960 && y < 2022) ? y : 1960;
		
		if (m == 2)
		{
			bool leap_year = false;
			if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
			{
				leap_year = true;
			}

			if (leap_year && d == 29)
				this->day = d;
		}
	}

	bool operator<(const Date& ref) const
	{
		if (this->year < ref.year)
		{
			return true;
		}
		else if (this->year == ref.year)
		{
			if (this->month < ref.month)
			{
				return true;
			}
			else if (this->month == ref.month)
			{
				if (this->day < ref.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Date& ref) const
	{
		if (this->year <= ref.year)
		{
			return true;
		}
		else
		{
			if (this->month <= ref.month)
			{
				return true;
			}
			else
			{
				if (this->day <= ref.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	bool operator>(const Date& ref) const
	{
		if (this->year > ref.year)
		{
			return true;
		}
		else if (this->year == ref.year)
		{
			if (this->month > ref.month)
			{
				return true;
			}
			else if (this->month == ref.month)
			{
				if (this->day > ref.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const Date& ref) const
	{
		if (this->year >= ref.year)
		{
			return true;
		}
		else
		{
			if (this->month >= ref.month)
			{
				return true;
			}
			else
			{
				if (this->day >= ref.day)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	bool operator==(const Date& ref) const
	{
		return (this->year == ref.year && this->month == ref.month && this->day == ref.day);
	}
	bool operator!=(const Date& ref) const
	{
		return (this->year == ref.year || this->month != ref.month || this->day != ref.day);
	}
	friend ostream& operator<<(ostream& out, const Date& ref);
};

ostream& operator<<(ostream& out, const Date& ref)
{
	cout << ref.day << "/" << ref.month << "/" << ref.year << "	-> DD/MM/YYYY";

	return out;
}

#endif // !DATE_H