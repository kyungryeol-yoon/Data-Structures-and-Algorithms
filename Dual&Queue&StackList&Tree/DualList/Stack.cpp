#include "Stack.h"

Stack::Stack()
{
	doublelist = new DoubleList;
}

Stack::~Stack()
{
}

void Stack::Push(int data, int position) {
	doublelist->insertNode(data, position);
}

void Stack::Pop(int position) {
	doublelist->delNode(position);
}

void Stack::display() {
	doublelist->displayNode();
}