#include<iostream>
#include"stack.h"

using namespace std;

int main()
{
	stack<int> stack1;
	stack<int> stack2;
	stack<int> sorted;
	stack<int> store_value;
	int num;

	//enter 5 elements for both stacks..
	cout << "Enter elements for Stack1: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		stack1.push(num);
	}

	cout << "Enter elements for Stack2: ";
	for (int i = 0; i < 5; i++)
	{
		cin >> num;
		stack2.push(num);
	}

	//logic...
	//push() any element in sorted stack
	//like 4.
	//then before every push(), we check if new element is greater or smaller then last elements.
	//if its greater, then push() at last
	//else start a loop where sorted.seek() < value to push
	//and store the pop() element in store_value stack.
	//then push the value and restore every element back from store_value stack.

	//for examle...
	//stack 1   ->  3 62 1
	//stack 2   ->  2 74 1

	//sort   ->   3      -> 3 62   
	//store  -> 62 3
	//sort   ->1         -> 1 3 62
	//.....

	sorted.push(stack1.pop());
	while (!stack1.isEmpty())
	{
		if (stack1.seek() >= sorted.seek())
		{
			sorted.push(stack1.pop());
		}
		else
		{
			while (stack1.seek() < sorted.seek())
			{
				store_value.push(sorted.pop());
				if (sorted.isEmpty())
				{
					break;
				}
			}
			sorted.push(stack1.pop());

			while (!store_value.isEmpty())
			{
				sorted.push(store_value.pop());
			}

		}
	}

	while (!stack2.isEmpty())
	{
		if (stack2.seek() >= sorted.seek())
		{
			sorted.push(stack2.pop());
		}
		else
		{
			while (stack2.seek() < sorted.seek())
			{
				store_value.push(sorted.pop());
				if (sorted.isEmpty())
				{
					break;
				}
			}
	
			sorted.push(stack2.pop());

			while (!store_value.isEmpty())
			{
				sorted.push(store_value.pop());
			}

		}
	}
	cout << "Sorted Merged Stack: " << endl;
	while (!sorted.isEmpty())
		cout << sorted.pop() << endl;

	return 0;
}