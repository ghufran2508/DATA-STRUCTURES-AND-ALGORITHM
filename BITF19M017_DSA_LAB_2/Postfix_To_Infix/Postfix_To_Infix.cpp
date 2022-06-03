#include<iostream>
#include"functions.h"
#include"stack.h"
#include<string>

using namespace std;

int main()
{
	stack<string> oprands;
	string postfix_expression;
	string infix_expression = "";
	string temp = "";

	cout << "Enter Valid Postfix Expression: ";
	getline(cin, postfix_expression);

	for (int i = 0; i < postfix_expression.size(); i++)
	{
		if (postfix_expression[i] == ' ')	continue;
		else if (isOperand(postfix_expression[i]))
		{
			//if it is an operand, than store the operand in the stack.
			temp = postfix_expression[i];
			oprands.push(temp);
		}
		else if (isOperator(postfix_expression[i]))
		{
			//if it found an operator, then there must be at least two elements in the stack.
			//the last pop() would give us operand2 and the second pop() would give us operand1
			//after calculating    -> temp = "(operand1 operator operand2 )";

			//for example...
			//ab*c+    stack   ->   a
			//			stack   ->   a | b
			//			stack   ->   (a*b)
			//			stack   ->   (a*b) | c
			//			stack   ->   ((a*b)+c)	->infix expression
			string op2 = oprands.pop();
			char op = postfix_expression[i];
			string op1 = oprands.pop();
			
			temp = "";

			temp += '(';
			temp += op1;
			temp += op;
			temp += op2;
			temp += ')';
			oprands.push(temp);
		}
	}
	infix_expression = oprands.pop();

	cout << "Infix Expression: " << infix_expression << endl;

	return 0;
}