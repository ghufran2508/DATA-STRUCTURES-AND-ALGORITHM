#include<iostream>
#include<stack>

using namespace std;

void TowerOfHanoi(stack<int>& A, stack<int>& B, stack<int>& C, int steps)
{
	if (steps == 1)
	{
		C.push(A.top());
		A.pop();
		return;
	}

	TowerOfHanoi(A, C, B, steps-1);
	C.push(A.top());
	A.pop();
	TowerOfHanoi(B, A, C, steps - 1);
}

int main()
{
	stack<int> stack1;
	stack<int> stack2;
	stack<int> stack3;

	int total_disks;
	cout << "Enter total disks: ";
	cin >> total_disks;

	while (total_disks < 0)
	{
		cout << "Enter total disks: ";
		cin >> total_disks;
	}

	for (int i = total_disks; i >= 1; i--)
	{
		stack1.push(i);
	}

	stack<int> temp = stack1;

	cout << "Stack1\tStack2\tStack3" << endl;
	while (!temp.empty())
	{
		cout << temp.top() << "\t" << 0 << "\t" << 0 << endl;
		temp.pop();
	}

	TowerOfHanoi(stack1, stack2, stack3, total_disks);

	cout << "\n After Processing...\n\n" << endl;

	cout << "Stack1\tStack2\tStack3" << endl;
	while (!stack3.empty())
	{
		cout << 0 << "\t" << 0 << "\t" << stack3.top() << endl;
		stack3.pop();
	}

	return 0;
}