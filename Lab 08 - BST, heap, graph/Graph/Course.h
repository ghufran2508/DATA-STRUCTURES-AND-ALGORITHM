#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Course_Node
{
	string name;
	int c_hours;
public:
	Course_Node* next;
	Course_Node(string name, int ch)
	{
		this->name = name;
		this->c_hours = ch;
		next = NULL;
	}
	string getName()const
	{
		return this->name;
	}
	int getCreditHour()const
	{
		return this->c_hours;
	}
};

class Course
{
	Course_Node* courses;
public:
	Course* next;
	Course()
	{
		courses = NULL;
		next = NULL;
	}
	Course(const Course& ref)
	{
		this->next = NULL;

		Course_Node* tempr = ref.getCourseNode();

		if (tempr != NULL)
		{
			courses = new Course_Node(tempr->getName(), tempr->getCreditHour());

			Course_Node* tempc = this->getCourseNode();

			tempr = tempr->next;

			while (tempr != NULL)
			{
				tempc->next = new Course_Node(tempr->getName(), tempr->getCreditHour());
				tempc = tempc->next;
				tempr = tempr->next;
			}
		}
		else
		{
			courses = NULL;
		}
	}
	bool addCourse(string name, int ch)
	{
		Course_Node* newcourse = new Course_Node(name,ch);

		if (!newcourse) return false;

		if (courses == NULL)
		{
			courses = newcourse;
			return true;
		}
		else
		{
			Course_Node* temp = courses;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = newcourse;
			return true;
		}
	}
	void addCourse(Course_Node* newcourse)
	{
		if (courses == NULL)
		{
			courses = newcourse;
		}
		else
		{
			Course_Node* temp = courses;

			while (temp->next != NULL)
				temp = temp->next;

			temp->next = newcourse;
		}
	}
	Course_Node* getCourseNode() const
	{
		return this->courses;
	}
	void printCourse()
	{
		Course_Node* temp = courses;

		cout << "\n****************************************\n";
		cout << "Course Name: " << this->courses->getName() << endl;
		cout << "Course Credit Hours: " << this->courses->getCreditHour() << endl;
		cout << courses->getName() << " is Linked with ";

		temp = temp->next;
		while (temp != NULL)
		{
			cout << temp->getName() << " " ;
			temp = temp->next;
		}
		cout << endl;
		cout << "\n****************************************\n";
	}
	/*~Course()
	{
		Course_Node* temp = courses;

		while (courses != NULL)
		{
			temp = courses;
			courses = courses->next;

			delete temp;
		}

		courses = NULL;
	}*/
};

class Graph
{
	Course* course_array;
	int getCourseIndex(const Course_Node& c)
	{
		int index = 0;
		Course* temp = course_array;

		while (temp != NULL)
		{
			Course_Node* check = temp->getCourseNode();
			if (check->getCreditHour() == c.getCreditHour() && check->getName() == c.getName())
			{
				return index;
			}
			temp = temp->next;
			index++;
		}
		return -1;
	}
public:
	Graph()
	{
		course_array = NULL;
	}
	Course* getCourse() const
	{
		return this->course_array;
	}
	void InsertVertex(Course new_course)
	{
		if (course_array == NULL)
		{
			course_array = &new_course;
			course_array->next = NULL;
		}
		else
		{
			Course* temp = course_array;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = &new_course;
			temp = temp->next;
			temp->next = NULL;
		}
	}
	void InsertVertex(Course *new_course)
	{
		if (course_array == NULL)
			course_array = new_course;
		else
		{
			Course* temp = course_array;

			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_course;
			temp = temp->next;
			temp->next = NULL;
		}
	}
	void InsertPair(Course &a, Course &b)
	{
		if (search(a) && search(b))
		{
			Course_Node* tempa = a.getCourseNode();
			Course_Node* tempb = b.getCourseNode();

			Course* temp = course_array;

			while (temp != NULL)
			{
				if (temp == &a)
				{
					temp->addCourse(tempb->getName(),tempb->getCreditHour());
				}
				if (temp == &b)
				{
					temp->addCourse(tempa->getName(),tempa->getCreditHour());
				}
				temp = temp->next;
			}
		}
	}
	bool search(Course& find)
	{
		Course* temp = course_array;
		Course_Node* check = find.getCourseNode();

		while (temp != NULL)
		{
			Course_Node* checkc = temp->getCourseNode();
			if (check->getCreditHour() == checkc->getCreditHour() && check->getName() == checkc->getName())
			{
				return true;
			}
			temp = temp->next;
		}

		return false;
	}
	void InOrderTraversal()
	{
		Course* temp = course_array;

		while (temp != NULL)
		{
			temp->printCourse();
			temp = temp->next;
		}
	}
	void DFS()
	{
		if (course_array == NULL)
			return;
		else
		{
			int total_node = 0;
			Course* temp = course_array;

			while (temp != NULL)
			{
				temp = temp->next;
				total_node++;
			}

			bool* visited = new bool[total_node];

			for (int i = 0; i < total_node; i++) visited[i] = false;

			temp = course_array;

			while (temp != NULL)
			{
				Course_Node* check = temp->getCourseNode();

				while (check != NULL)
				{
					if (visited[this->getCourseIndex(*check)] == false)
					{
						visited[this->getCourseIndex(*check)] = true;
						cout << check->getName() << " - ";
					}

					check = check->next;
				}
				temp = temp->next;
			}
		}
	}
	/*~Graph()
	{
		Course* temp = course_array;

		while (temp != NULL)
		{
			temp = course_array;
			course_array = course_array->next;

			delete temp;
		}
		course_array = NULL;
	}*/
};

#endif // !GRAPH_H


//#include<iostream>
//#include"Graph.h"
//
//using namespace std;
//
//int main()
//{
//	Course a;
//	a.addCourse("PF", 3);
//
//	Course b;
//	b.addCourse("OOP", 3);
//
//	Course c;
//	c.addCourse("DSA", 3);
//
//	Graph PUCIT;
//
//	PUCIT.InsertVertex(&a);
//	PUCIT.InsertVertex(&b);
//	PUCIT.InsertVertex(&c);
//
//	PUCIT.InsertPair(a, b);
//	PUCIT.InsertPair(b, c);
//
//	PUCIT.InOrderTraversal();
//
//	PUCIT.DFS();
//
//	return 0;
//}
