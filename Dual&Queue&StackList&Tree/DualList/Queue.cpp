#include "Queue.h"

Queue::Queue()
{
	doublelist = new DoubleList;
}

Queue::~Queue()
{
}

void Queue::enqueue(int data, int _position) {
	doublelist->insertNode(data, _position);
}

void Queue::dequeue(int position) {
	doublelist->delNode(position);
}

void Queue::display() {
	doublelist->displayNode();
}