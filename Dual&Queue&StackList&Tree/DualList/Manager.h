#pragma once
#include "DoubleList.h"
#include "Queue.h"
#include "Stack.h"
#include "Tree.h"

enum Menu
{
	INSERT = 1,
	DEL = 2,
	COUT = 3,
	ALLDEL = 4,
	COUNTNODE = 5,
	SEARCH = 6,
	BUBBLESORT = 7,
	INSERTSORT = 8,
	QUICKSORT = 9,
	REVERSE = 10,
};

class Manager
{
private:
	int find;

	DoubleList *doublelist;
	Stack *stack;
	Queue *queue;
	Tree *tree;
public:
	Manager();
	~Manager();

	void Doublerun();
	void QueueRun();
	void StackRun();
	void TreeRun();
};