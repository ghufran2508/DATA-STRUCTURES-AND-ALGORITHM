#pragma once
#ifndef BST_H
#define BST_H

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
public:
	BST()		// 0.5- number
	{
		root = NULL;
	}
	void insert(T val)		// 1.5- number
	{
		Node* newnode = new Node;
		newnode->data = val;
		
		if(root == NULL)
		{
			root = val;
		}
		else
		{
			
		}
	}
	void remove(T val);		// 2.5-	number
	void printInOrder()const;	// 1.5- number
	void printPostOrder()const;	// 1.5- number
	void printLevelOrder(int k)const;	// 2- number
	void replace(T old_val, T new_val); // 5- number
	~BST();		// 0.5- number
};




#endif // BST_H
