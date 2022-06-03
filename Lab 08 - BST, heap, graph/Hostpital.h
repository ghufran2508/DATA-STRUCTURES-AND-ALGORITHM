#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include<iostream>
using namespace std;
class Hospital{ // 6- marks
	string HospitalName;
	string Address;
	string HospitalID;
public:
	Hospital();		// 0.25- marks
	Hospital(string ,string,string); // 0.25- marks
	Hospital(string HospitalID); // conversion Constructor // 0.5- marks
	string getHospitalName()const; // 0.25- marks
	string getHospitalId()const; // 0.25- marks
	string getAddress()const; // 0.25- marks
	void setHospitalName(string); // 0.25- marks
	void setHospitalId(string); // 0.25- marks
	void setAddress(string); // 0.25- marks

	// Relational operators with respect to Hospital Id
	bool operator<(Hospital)const; // 0.5- marks
	bool operator<=(Hospital)const; // 0.5- marks
	bool operator>(Hospital)const; // 0.5- marks
	bool operator>=(Hospital)const; // 0.5- marks
	bool operator==(Hospital)const; // 0.5- marks
	bool operator!=(Hospital)const; // 0.5- marks
	// output stream operator
	friend ostream& operator<<(ostream&, const Hospital& ref); // 0.5- marks

};
ostream& operator<<(ostream&, const Hospital& ref);

class MaxHeap {	// 9
public:
	class Node {
	public:
		Hospital data;
		Node* left;
		Node* right;
	};
private:
	Node* root;
public:
	MaxHeap();	//	0.5- marks
	bool Insert(Hospital); // 2- marks
	bool Remove(Hospital); // 2- marks
	bool Replace(Hospital old_Hos, Hospital new_Hos); // 3- marks
	Hospital* getHeapArray()const; // 1-mark
	~MaxHeap();	//	0.5- marks
};
#endif // HOSPITAL_H