#include<iostream>
#include<string>
#include"queue.h"

using namespace std;

bool isUpper(string word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
			return false;
	}
	return true;
}

void toUpper(string& word)
{
	for (int i = 0; i < word.size(); i++)
	{
		if (word[i] >= 'a' && word[i] <= 'z')
			word[i] -= 32;
	}
}

void process(Deque& A, Deque& B, Deque& C)
{
	int counta = 0, countb = 0, countc = 0;
	string worda, wordb, wordc, temp;

	if (!A.isEmpty())
	{
		worda = A.deleteFront();
		if (!isUpper(worda))
		{
			counta++;
		}
		else
		{
			toUpper(worda);
		}
		temp = worda;
		A.insertRear(worda);
	}

	do
	{
		if (A.isEmpty())break;
 
		worda = A.deleteFront();
		if (!isUpper(worda))
		{
			counta++;
		}
		else
		{
			toUpper(worda);
		}
		A.insertRear(worda);
	} while (worda != temp);

	if (!B.isEmpty())
	{
		wordb = B.deleteFront();
		if (!isUpper(wordb))
		{
			countb++;
		}
		else
		{
			toUpper(wordb);
		}
		temp = wordb;
		B.insertRear(wordb);
	}

	do
	{
		if (B.isEmpty()) break;
		wordb = B.deleteFront();
		if (!isUpper(wordb))
		{
			countb++;
		}
		else
		{
			toUpper(wordb);
		}
		B.insertRear(wordb);
	} while (wordb != temp);

	if (!C.isEmpty())
	{
		wordc = C.deleteFront();
		if (!isUpper(wordc))
		{
			countc++;
		}
		else
		{
			toUpper(wordc);
		}
		temp = wordc;
		C.insertRear(wordc);
	}

	do
	{
		if (C.isEmpty()) break;
		wordc = C.deleteFront();
		if (!isUpper(wordc))
		{
			countc++;
		}
		else
		{
			toUpper(wordc);
		}
		C.insertRear(wordc);
	} while (wordc != temp);

	if (counta < countb && counta < countc)
	{
		cout << "A Deque will be processed first and " << counta << " entries are processed in this queue" << endl;
	}
	else if (countb < counta && countb < countc)
	{
		cout << "B Deque will be processed first and " << countb << " entries are processed in this queue" << endl;
	}
	else
	{
		cout << "C Deque will be processed first and " << countc << " entries are processed in this queue" << endl;
	}
}

int main()
{
	Deque a, b, c;
	string s;

	do {
		cout << "Enter Word : ";
		cin >> s;
		if (s != "END")
		{
			cout << "Enter the Queue in which you Want to Enque : ";
			char ch;
			cin >> ch;
			switch (ch)
			{
			case 'A':
				a.insertFront(s);
				break;
			case 'B':
				b.insertFront(s);
				break;
			case 'C':
				c.insertFront(s);
				break;
			}
		} // end if s!=END
	} while (s != "END");
	process(a, b, c);
	return 0;
}