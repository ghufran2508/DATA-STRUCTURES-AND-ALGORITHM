#include<iostream>
#include<queue>
#include<ctime>
#include<string>

using namespace std;

class Person
{
	string name;
	int priority;
	time_t current_time;
public:
	void setName(int priority)
	{
		if (priority == 1)
			name = "Student";
		if (priority == 2)
		{
			name = "Teacher";
		}
	}
	string getName()
	{
		return this->name;
	}
	void setPriority(int p)
	{
		this->priority = p;
	}
	int getPriority()
	{
		return this->priority;
	}
	void setTime(time_t curr_t)
	{
		current_time = curr_t;
	}
	time_t getTime()
	{
		return this->current_time;
	}
	friend bool operator<(const Person& lhs, const Person& rhs);
};

bool operator<(const Person& lhs, const Person& rhs)
{
	return lhs.priority < rhs.priority;
}

int main()
{
	priority_queue<Person> school_queue;
	Person school_character;
	int teacherCount = 0, studentCount = 0;
	time_t student_time = 0, teacher_time = 0, past = time(0);
	bool queue = true;
	int priority;
	int check;

	do
	{
		cout << "\nPlease Choose the following...." << endl;
		cout << "1. Enter Teacher." << endl;
		cout << "2. Enter Student." << endl;
		cout << "3. Dequeue." << endl;
		cout << "4. Exit." << endl;
		cin >> check;

		while (check < 1 || check > 4)
		{
			cin >> check;
		}

		switch (check)
		{
		case 1:
			school_character.setName(2);
			school_character.setPriority(2);
			school_character.setTime(time(0));
			school_queue.push(school_character);
			cout << "\n****************************" << endl;
			cout << "\tTeacher Added!" << endl;
			cout << "****************************\n" << endl;
			break;
		case 2:
			school_character.setName(1);
			school_character.setPriority(1);
			school_character.setTime(time(0));
			school_queue.push(school_character);
			cout << "\n****************************" << endl;
			cout << "\tStudent Added!" << endl;
			cout << "****************************\n" << endl;
			break;
		case 3:
			if (school_queue.empty())
			{
				queue = false;
				break;
			}
			
			school_character = school_queue.top();

			if (school_character.getPriority() == 1)
			{
				studentCount++;
				cout << "\n****************************" << endl;
				cout << "Result book received." << endl;
				cout << "****************************\n" << endl;
				student_time += school_character.getTime();
			}
			else
			{
				teacherCount++;
				cout << "\n****************************" << endl;
				cout << "Result submitted." << endl;
				cout << "****************************\n" << endl;
				teacher_time += school_character.getTime();
			}

			school_queue.pop();
			break;
		case 4:
			queue = false;
			break;
		}

	} while (queue);

	cout << "\nTeacher Processed: " << teacherCount << endl;
	cout << "Student Processed: " << studentCount << endl;
	if(teacherCount == 0)
		cout << "Teacher Awaited Time = " << 0 << " sec." << endl;
	else
	{
		cout << "Teacher Awaited Time = " << teacher_time / teacherCount - past << " sec." << endl;
	}
	if (studentCount == 0)
	{
		cout << "Student Awaited Time = " << 0 << " sec." << endl;
	}
	else
	{
		cout << "Student Awaited Time = " << student_time / studentCount - past << " sec." << endl;
	}

	return 0;
}