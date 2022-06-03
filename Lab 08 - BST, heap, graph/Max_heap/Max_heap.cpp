#include<iostream>
#include"Hospital.h"
using namespace std;

int main()
{
	MaxHeap a;
	a.Insert(Hospital("Meo", "Lahore", "HL1"));
	a.Insert(Hospital("Jinnah", "Lahore", "HL2"));
	a.Insert(Hospital("Civil", "Lahore", "HL3"));
	a.Insert(Hospital("Cardialogy", "Lahore", "HL4"));
	a.Insert(Hospital("Nishtar", "Multan", "HM1"));
	a.Insert(Hospital("Punjab Medical", "Faisalabad", "HF1"));
	a.Insert(Hospital("Allied", "Faisalabad", "HF2"));

	Hospital* ptr = a.getHeapArray();
	for (int i = 0; i < 7; i++)
	{
		cout << i[ptr] << endl;
	}
	delete[] ptr;
	a.Remove(Hospital("HF2"));
	a.Replace(Hospital("HL4"), Hospital("THQ", "Burewala", "HB1"));
	ptr = a.getHeapArray();
	for (int i = 0; i < 6; i++)
	{
		cout << i[ptr] << endl;
	}
	delete[] ptr;
	return 0;
}