#pragma once
#include "DoubleList.h"

class Queue
{
private:
	DoubleList *doublelist;
public:
	Queue();
	~Queue();
	
	DoubleList *getdouble() { return doublelist; }

	void enqueue(int data, int position);
	void dequeue(int position);
	void display();
};