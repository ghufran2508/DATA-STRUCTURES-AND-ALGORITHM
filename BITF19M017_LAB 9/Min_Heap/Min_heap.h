#pragma once

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include<iostream>
#include<stack>
#include<queue>
#include"Employee.h"

using namespace std;

class Node {
public:
	Employee data;
	Node* left;
	Node* right;
};

class MinHeap {	

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
			if (!ref->right)
			{
				if (ref->left->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
			}
			else
			{
				if (ref->left->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
				else if (ref->right->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->right->data;
					ref->right->data = temporary;
				}
			}
			heapify(ref->left);
			heapify(ref->right);

			if (ref->left && !ref->right)
			{
				if (ref->left->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
			}
			else
			{
				if (ref->left->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->left->data;
					ref->left->data = temporary;
				}
				else if (ref->right->data < ref->data)
				{
					Employee temporary = ref->data;
					ref->data = ref->right->data;
					ref->right->data = temporary;
				}
			}
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
	Node* search(Employee ref)
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
	MinHeap()	//	0.5- marks
	{
		root = NULL;
	}
	bool Insert(Employee H_add) // 2- marks
	{
		Node* newEmployee = new Node;

		if (!newEmployee)	return false;

		newEmployee->data = H_add;
		newEmployee->left = NULL;
		newEmployee->right = NULL;

		if (root == NULL)
		{
			root = newEmployee;
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

			if (check->left == NULL)
			{
				check->left = newEmployee;
			}
			else
			{
				check->right = newEmployee;
			}
		}
		heapify(root);
		return true;
	}
	Employee getMostSenior()
	{
		if (this->root)
		{
			return root->data;
		}
		else
			exit(0);
	}
	bool RemoveMostSenior()
	{
		if (this->root)
		{
			Remove(root->data);
			return true;
		}
		else
			return false;
	}
	bool Remove(Employee del_Emp) // 2- marks
	{
		if (root == NULL) return false;

		Node* to_delete = search(del_Emp);

		if (to_delete == NULL) return false;

		Node* lnode = lastNode(root);

		if (root->data == lnode->data)
		{
			delete root;
			root = NULL;
			return true;
		}

		to_delete->data = lnode->data;

		queue<Node*> temp;
		temp.push(root);
		Node* check;

		while (!temp.empty())
		{
			check = temp.front();
			temp.pop();

			if (check->left->data == lnode->data)
			{
				check->left = NULL;
				break;
			}
			if (check->right->data == lnode->data)
			{
				check->right = NULL;
				break;
			}
			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}

		delete lnode;

		heapify(root);
		return true;
	}
	bool Replace(Employee old_Emp, Employee new_Emp) // 3- marks
	{
		Node* to_change = search(old_Emp);

		if (to_change == NULL)
			return false;
		else
		{
			to_change->data = new_Emp;

			heapify(root);
			return true;
		}
	}
	Employee* getHeapArray() const // 1-mark
	{
		int size = total_node(root);
		if (size == 0) return NULL;
		Employee* emp_array = new Employee[size];

		queue<Node*> temp;
		temp.push(root);
		int index = 0;

		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			emp_array[index] = check->data;
			index++;

			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}

		return emp_array;
	}
	void printEmployeeInOrder()
	{
		queue<Node*> temp;

		temp.push(root);

		while (!temp.empty())
		{
			Node* check = temp.front();
			temp.pop();

			cout << check->data << endl;

			if (check->left)
				temp.push(check->left);
			if (check->right)
				temp.push(check->right);
		}
	}
	~MinHeap()	//	0.5- marks
	{
		if (root)
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
	}
};


#endif // !MIN_HEAP_H
