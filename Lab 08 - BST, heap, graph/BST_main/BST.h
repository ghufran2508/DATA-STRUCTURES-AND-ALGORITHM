#pragma once
#ifndef BST_H
#define BST_H

#include<iostream>
#include<stack>

using namespace std;

template<class T>
class BST {		// 15- number
public:
	class Node {
	public:
		T data;
		Node* left;
		Node* right;
	};
private:
	Node* root;
	Node* deleteNode(Node* ref, int value)
	{
		if (ref == NULL)
			return ref;
		else if (ref->data > value)
			ref->left = deleteNode(ref->left, value);
		else if (ref->data < value)
			ref->right = deleteNode(ref->right, value);
		else
		{
			if (!ref->left && !ref->right)
			{
				delete ref;
				ref = NULL;
			}
			else if (!ref->left)
			{
				Node* temp = ref;
				ref = ref->right;
				delete temp;
			}
			else if (!ref->right)
			{
				Node* temp = ref;
				ref = ref->left;
				delete temp;
			}
			else
			{
				Node* temp = this->findMin(ref->right);
				ref->data = temp->data;
				ref->right = deleteNode(ref->right, temp->data);
			}
		}
		return ref;
	}
	void inOrderTraversal(Node* ref) const
	{
		if (ref == NULL)
			return;
		else
		{
			inOrderTraversal(ref->left);
			cout << ref->data << " ";
			inOrderTraversal(ref->right);
		}
	}
	void postOrderTraversal(Node* ref) const
	{
		if (ref == NULL)
			return;
		else
		{
			postOrderTraversal(ref->left);
			postOrderTraversal(ref->right);
			cout << ref->data << " ";
		}
	}
	void levelOrderTraversal(Node* ref, int k) const
	{
		if (ref == NULL)
			return;
		else if (k == 1)
			cout << ref->data << " ";
		else
		{
			levelOrderTraversal(ref->left, k - 1);
			levelOrderTraversal(ref->right, k - 1);
		}
	}
	//return node of minimum value of tree ref...
	Node* findMin(Node* ref)
	{
		if (ref == NULL)
			return ref;

		while (ref->left != NULL)
			ref = ref->left;
		return ref;
	}
	//refactor function
	//this function will check if ref->left value is less and ref->right value is greater then ref.
	//if not, it will swap the value.
	void refactor(Node* ref)
	{
		if (ref == NULL)
			return;

		if (ref->left && ref->data < ref->left->data)
		{
			T temporary = ref->data;
			ref->data = ref->left->data;
			ref->left->data = temporary;
		}
		if (ref->right && ref->data > ref->right->data)
		{
			T temporary = ref->data;
			ref->data = ref->right->data;
			ref->right->data = temporary;
		}

		refactor(ref->left);
		refactor(ref->right);

		if (ref->left && ref->data < ref->left->data)
		{
			T temporary = ref->data;
			ref->data = ref->left->data;
			ref->left->data = temporary;
		}
		if (ref->right && ref->data > ref->right->data)
		{
			T temporary = ref->data;
			ref->data = ref->right->data;
			ref->right->data = temporary;
		}
	}
public:
	BST()		// 0.5- number
	{
		//setting root to null initially
		root = NULL;
	}
	void insert(T val)		// 1.5- number
	{
		//creating a new node of value null.
		//first getting new pointer of Node
		Node* newnode = new Node;
		//then setting value
		newnode->data = val;
		//then seeting left and right node to NULL, means it is not pointing to any node.
		newnode->left = NULL;
		newnode->right = NULL;
		if (root == NULL)
		{
			//is there is no node, then set newnode as root
			root = newnode;
		}
		else
		{
			//find, where should the newnode be placed.
			Node* parent = NULL;
			Node* temp = root;

			while (1)
			{
				parent = temp;
				//if new value is smaller, then go left, else go right.
				if (parent->data > newnode->data)
				{
					//if it is a leaf node, then place it.
					temp = temp->left;
					if (temp == NULL)
					{
						parent->left = newnode;
						return;
					}
				}
				else
				{
					temp = temp->right;

					if (temp == NULL)
					{
						parent->right = newnode;
						return;
					}
				}
			}
		}
	}
	//this function will remove the value from BST
	void remove(T val)		// 2.5-	number
	{
		this->deleteNode(root, val);
	}
	void printInOrder() const	// 1.5- number
	{
		this->inOrderTraversal(root);
		cout << endl;
	}
	void printPostOrder()const	// 1.5- number
	{
		this->postOrderTraversal(root);
		cout << endl;
	}
	void printLevelOrder(int k)const	// 2- number
	{
		this->levelOrderTraversal(root, k);
	}
	void replace(T old_val, T new_val) // 5- number
	{
		//check where the node is...
		Node* temp = root;

		while (1)
		{
			if (temp == NULL)
			{
				cout << "Old Value does not found!!!" << endl;
				return;
			}
			if (temp->data == old_val)	//if found, then break, means it is the node we want to replace.
			{
				temp->data = new_val;
				break;
			}
			else if (temp->data < old_val)
				temp = temp->right;
			else
				temp = temp->left;
		}
		//caaling refactor function to set the wrong node....
		this->refactor(root);
	}
	~BST()		// 0.5- number
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




#endif // BST_H