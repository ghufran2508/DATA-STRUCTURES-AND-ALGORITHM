#pragma once
#include<iostream>
#include"stack.h"

using namespace std;


bool isOperand(char character)
{
	if (character >= 'A' && character <= 'Z')
		return true;
	if (character >= 'a' && character <= 'z')
		return true;
	if (character >= '0' && character <= '9')
		return true;

	return false;
}

bool isOperator(char character)
{
	if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
	{
		return true;
	}
	return false;
}

int operatorPrecedence(char op)
{
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	if (op == '^')
		return 3;

	return 0;
}