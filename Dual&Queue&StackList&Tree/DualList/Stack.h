#pragma once
#include "DoubleList.h"

class Stack
{
private:
	DoubleList *doublelist;
public:
	Stack();
	~Stack();
	
	DoubleList *getdouble() { return doublelist; }

	void Push(int data, int position);
	void Pop(int position);
	void display();
};

