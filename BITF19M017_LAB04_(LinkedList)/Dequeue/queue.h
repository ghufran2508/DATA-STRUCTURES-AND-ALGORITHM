#pragma once

#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include"LinkedList.h"
using namespace std;

class Deque {
    LinkList queued;
public:
    bool isEmpty() {
        return queued.isEmpty();
    }
    void insertFront(string x) {
        queued.insertAtHead(x);
    }
    string deleteFront() {
        return queued.RemoveAtHead();
    }
    void insertRear(string x)
    {
        queued.insertAtTail(x);
    }
    string deleteRear()
    {
        return queued.RemoveAtTail();
    }
};

#endif // !QUEUE_H