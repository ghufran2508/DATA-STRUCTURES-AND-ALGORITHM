#pragma once
#ifndef HOSPITAL_H
#define HOSPITAL_H
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
class Hospital { // 6- marks
	string HospitalName;
	string Address;
	string HospitalID;
public:
	Hospital()		// 0.25- marks
	{
		HospitalName = "NULL";
		Address = "NULL";
		HospitalID = "NULL";
	}
	Hospital(string name, string address, string id) // 0.25- marks
	{
		this->HospitalName = name;
		this->Address = address;
		this->HospitalID = id;
	}
	Hospital(string HospitalID) // conversion Constructor // 0.5- marks
	{
		this->HospitalID = HospitalID;
		this->HospitalName = "NULL";
		this->Address = "NULL";
	}
	string getHospitalName() const // 0.25- marks
	{
		return this->HospitalName;
	}
	string getHospitalId() const // 0.25- marks
	{
		return this->HospitalID;
	}
	string getAddress() const // 0.25- marks
	{
		return this->Address;
	}
	void setHospitalName(string name) // 0.25- marks
	{
		this->HospitalName = name;
	}
	void setHospitalId(string id)  // 0.25- marks
	{
		this->HospitalID = id;
	}
	void setAddress(string address) // 0.25- marks
	{
		this->Address = address;
	}

	// Relational operators with respect to Hospital Id
	bool operator<(Hospital ref) const // 0.5- marks
	{
		return (this->HospitalID < ref.HospitalID);
	}
	bool operator<=(Hospital ref) const // 0.5- marks
	{
		return (this->HospitalID <= ref.HospitalID);
	}
	bool operator>(Hospital ref) const  // 0.5- marks
	{
		return (this->HospitalID > ref.HospitalID);
	}
	bool operator>=(Hospital ref) const // 0.5- marks
	{
		return (this->HospitalID >= ref.HospitalID);
	}
	bool operator==(Hospital ref) const // 0.5- marks
	{
		return (this->HospitalID == ref.HospitalID);
	}
	bool operator!=(Hospital ref) const  // 0.5- marks
	{
		return (this->HospitalID != ref.HospitalID);
	}
	// output stream operator
	friend ostream& operator<<(ostream&, const Hospital& ref); // 0.5- marks

};
ostream& operator<<(ostream& out, const Hospital& ref)
{
	out << "\n******************************************\n" << endl;
	out << "Hopital Name: " << ref.HospitalName << endl;
	out << "Hopital ID: " << ref.HospitalID << endl;
	out << "Hopital Adress: " << ref.Address << endl;
	out << "\n******************************************\n" << endl;

	return out;
}

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
	void heapify(Node* ref)
	{
		if (ref == lastNode(ref)) return;
		if (!ref->left && !ref->right)
		{
			return;
		}
		else
		{
			if (ref->left && !ref->right)
			{
				if (ref->left->data > ref->data)
				{
					Hospital temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
			}
			else
			{
				if (ref->left->data > ref->data)
				{
					Hospital temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
				else if (ref->right->data > ref->data)
				{
					Hospital temporary = ref->data;
					ref->data = ref->right->data;
					ref->right->data = temporary;
				}
			}
			heapify(ref->left);
			heapify(ref->right);
		}
	}
	int total_node(Node* ref) const
	{
		if (root == NULL)
			return 0;
		queue<Node*> temp;
		temp.push(ref);
		int count = 1;
		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			if (check->left)
			{
				temp.push(check->left);
				count++;
			}
			if (check->right)
			{
				temp.push(check->right);
				count++;
			}
		}

		return count;
	}
	Node* search(Hospital ref)
	{
		if (root == NULL)
			return NULL;
		queue<Node*> temp;
		temp.push(root);

		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			if (check->data == ref)
				return check;

			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}

		return NULL;
	}
	Node* lastNode(Node* ref)
	{
		if (ref == NULL)
			return NULL;

		queue<Node*> temp;
		temp.push(ref);
		Node* check = NULL;

		while (!temp.empty())
		{
			check = temp.front();
			temp.pop();

			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}

		return check;
	}
public:
	MaxHeap()	//	0.5- marks
	{
		root = NULL;
	}
	bool Insert(Hospital H_add) // 2- marks
	{
		Node* newHospital = new Node;

		if (!newHospital)	return false;
		
		newHospital->data = H_add;
		newHospital->left = NULL;
		newHospital->right = NULL;

		if (root == NULL)
		{
			root = newHospital;
			return true;
		}
		else
		{
			queue<Node*> temp;
			temp.push(root);
			Node* check = NULL;
			while (!temp.empty())
			{
				check = temp.front();
				temp.pop();

				if (check->left && check->right)
				{
					temp.push(check->left);
					temp.push(check->right);
				}
				else
				{
					break;
				}
			}

			if (!check->left)
			{
				check->left = newHospital;
			}
			else
			{
				check->right = newHospital;
			}
		}
		heapify(root);
		return true;
	}
	bool Remove(Hospital delH) // 2- marks
	{
		if (root == NULL) return false;

		Node* to_delete = search(delH);

		if (to_delete == NULL) return false;

		Node* lnode = lastNode(root);

		if (root == lnode)
		{
			delete root;
			root = NULL;
			return true;
		}

		to_delete->data = lnode->data;
		
		queue<Node*> temp;
		temp.push(root);

		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			if (check->left == lnode)
			{
				check->left = NULL;
				break;
			}
			if (check->right == lnode)
			{
				check->right = NULL;
				break;
			}
		}

		heapify(root);
	}
	bool Replace(Hospital old_Hos, Hospital new_Hos) // 3- marks
	{
		Node* to_change = search(old_Hos);

		if (to_change == NULL)
			return false;
		else
		{
			to_change->data = new_Hos;

			heapify(root);
			return true;
		}
	}
	Hospital* getHeapArray() const // 1-mark
	{
		int size = total_node(root);
		if (size == 0) return NULL;
		Hospital* h_array = new Hospital[size];

		queue<Node*> temp;
		temp.push(root);
		int index = 0;

		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			h_array[index] = check->data;
			index++;

			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}

		return h_array;
	}
	~MaxHeap()	//	0.5- marks
	{
		stack<Node*> temp;

		temp.push(root);

		while (!temp.empty())
		{
			Node* to_delete = temp.top();
			temp.pop();

			if (to_delete->left)
				temp.push(to_delete->left);
			if (to_delete->right)
				temp.push(to_delete->right);

			delete to_delete;
		}
	}
};
#endif // HOSPITAL_H