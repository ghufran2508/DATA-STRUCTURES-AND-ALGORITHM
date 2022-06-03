#pragma once
#include<iostream>

using namespace std;

class TwoStack
{
    int* arr;
    int size;
    int Top1;
    int Top2;
public:
    TwoStack();// build array of size 10
    TwoStack(int size);
    bool push1(int);
    bool push2(int);
    int pop1();
    int pop2();
    int top1() const;
    int top2() const;
    bool empty1() const;
    bool empty2() const;
    bool full1() const;
    bool full2() const;
    ~TwoStack();

};

TwoStack::TwoStack()
{
    this->size = 10;
    this->arr = new int[size];
    this->Top1 = -2;
    this->Top2 = -1;
}

TwoStack::TwoStack(int size)
{
    this->size = (size > 1) ? size: 10;
    this->arr = new int[size];
    this->Top1 = -2;
    this->Top2 = -1;
}

bool TwoStack::push1(int value)
{
    if (Top1 == size - 2)
        return false;
    else
    {
        Top1 += 2;
        arr[Top1] = value;
        return true;
    }
}

bool TwoStack::push2(int value)
{
    if (Top2 == size - 1)
        return false;
    else
    {
        Top2 += 2;
        arr[Top2] = value;
        return true;
    }
}

int TwoStack::pop1()
{
    if (Top1 == -2)
    {
        cout << "Stack is Empty!!!" << endl;
    }
    else
    {
        int value = arr[Top1];
        Top1 -= 2;
        return value;
    }
}

int TwoStack::pop2()
{
    if (Top2 == -1)
    {
        cout << "Stack is Empty!!!" << endl;
    }
    else
    {
        int value = arr[Top2];
        Top2 -= 2;
        return value;
    }
}

int TwoStack::top1() const
{
    return Top1;
}

int TwoStack::top2() const
{
    return Top2;
}

bool TwoStack::empty1() const
{
    return (Top1 == -2);
}

bool TwoStack::empty2() const
{
    return (Top2 == -1);
}

bool TwoStack::full1() const
{
    return (Top1 == size - 2);
}

bool TwoStack::full2() const
{
    return (Top2 == size - 1);
}

TwoStack::~TwoStack()
{
    delete[] arr;
    arr = NULL;
}