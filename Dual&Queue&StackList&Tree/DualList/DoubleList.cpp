#include "DoubleList.h"

DoubleList::DoubleList() : IDCount(0), Head(NULL), Tail(NULL)
{
}

DoubleList::~DoubleList()
{
}

void DoubleList::insertNode(int _data, int _position) {
	++IDCount;
	Node *newNode = new Node;
	newNode->setData(_data);
	newNode->SetID(IDCount);
	
	if (Head == NULL) {
		Head = newNode;
		Tail = Head;
	}
	else {
		if (_position == 0) {
			newNode->setRlink(Head);
			Head->setLlink(newNode);
			Head = newNode;
		}
		else if (_position == -1) {
			newNode->setLlink(Tail);
			Tail->setRlink(newNode);
			Tail = newNode;
		}
		else {
			Node *before = Head;
			while ((--_position) > 0)
			{
				before = before->getRlink();
			}
			if (before->getRlink() != NULL) {
				before->getRlink()->setLlink(newNode);
			}
			newNode->setLlink(before);
			newNode->setRlink(before->getRlink());
			before->setRlink(newNode);
		}
	}
}

void DoubleList::delNode(int _location) {
	if (_location == 0) {
		Head = Head->getRlink();
		if (Head != NULL) {
			Head->setLlink(NULL);
		}
	}
	else {
		Node *before = Head;
		while ((--_location) > 0)
		{
			before = before->getRlink();
		}
		Node *after = before->getRlink()->getRlink();
		if (after != NULL) {
			before->setRlink(after);
			after->setLlink(before);
		}
		else {
			before->setRlink(NULL);
		}
	}
}

void DoubleList::displayNode() {
	Node *Temp = Head;
	while (true)
	{
		if (Temp == NULL) {
			break;
		}
		else {
			cout << "ID:" << Temp->GetID() << " Data:" << Temp->getData() << endl;
			Temp = Temp->getRlink();
		}
	}
}

void DoubleList::AllDel() {
	while (true)
	{
		if (Head == NULL) {
			break;
		}
		else {
			delNode(0);
		}
	}
}

int DoubleList::CountNode() {
	int count = 0;

	Node *now = new Node;
	for (now = Head; now; now = now->getRlink()) {
		count++;
	}
	return count;
}

int DoubleList::Find(int _location) {
	Node *current = Head;
	while ((--_location) >= 1) {
		current = current->getRlink();
	}
	return current->getData();
}

Node *DoubleList::ArrangeNode(int pos) {
	Node *Current = Head;
	for (int i = 0; i < pos; i++) {
		Current = Current->getRlink();
	}
	return Current;
}

void DoubleList::BubbleSort() {
	Node *Current(NULL);
	for (int i = 0; i < CountNode() - 1; i++) {
		Current = Head;
		for (int j = 0; j < CountNode() - (i + 1); j++) {
			if (Current->getData() > Current->getRlink()->getData()) {
				Node *tmp = Current->getRlink();
				if (tmp == NULL) {
					return;
				}
				if (Current == Head) {
					Head = tmp;
					if (tmp == Tail) {
						Tail = Current;
					}
					else if(tmp != Tail)
					{
						tmp->getRlink()->setLlink(Current);
					}
				}
				else if (tmp == Tail) {
					Tail = Current;
					Current->getLlink()->setRlink(tmp);
				}
				else {
					tmp->getRlink()->setLlink(Current);
					Current->getLlink()->setRlink(tmp);
				}
				Current->setRlink(tmp->getRlink());
				tmp->setLlink(Current->getLlink());

				Current->setLlink(tmp);
				tmp->setRlink(Current);
				
				Current = tmp;
			}
			Current = Current->getRlink();
		}
	}
}

void DoubleList::InsertSort() {
	Node *Current(NULL);
	for (int i = 1; i < CountNode(); i++) {
		Current = ArrangeNode(i);
		for (int j = i; j > 0; j--) {
			if (Current->getData() < Current->getLlink()->getData()) {
				Node *tmp = Current->getLlink();
				if (tmp == Head) {
					Head = Current;
					if (Current == Tail) {
						Tail = tmp;
					}
					else if (Current != Tail) {
						Current->getRlink()->setLlink(tmp);
					}
				}
				else if (Current == Tail) {
					Tail = tmp;
					tmp->getLlink()->setRlink(Current);
				}
				else {
					tmp->getLlink()->setRlink(Current);
					Current->getRlink()->setLlink(tmp);
				}
				Current->setLlink(tmp->getLlink());
				tmp->setRlink(Current->getRlink());

				Current->setRlink(tmp);
				tmp->setLlink(Current);

				Current = tmp;
			}
			Current = Current->getLlink();
		}
	}
}

void DoubleList::QuickSort(int Left, int Right)
{
	if (Left < Right) {
		int index = Partition(Left, Right);

		QuickSort(Left, index - 1);
		QuickSort(index + 1, Right);
	}
}

int DoubleList::Partition(int Left, int Right)
{
	int first = Left;
	int pivot = ArrangeNode(first)->getData();
	++Left;
	while (Left <= Right)
	{
		while (ArrangeNode(Left)->getData() <= pivot && Left < Right) {
			++Left;
		}
		while (ArrangeNode(Right)->getData() > pivot && Left <= Right) {
			--Right;
		}
		if (Left < Right) {
			Swap(ArrangeNode(Left), ArrangeNode(Right));
		}
		else {
			break;
		}
	}
	Swap(ArrangeNode(first), ArrangeNode(Right));

	return Right;
}

void DoubleList::Swap(Node * tmp1, Node * tmp2)
{
	Node *tmp1Llink = tmp1->getLlink();
	Node *tmp1Rlink = tmp1->getRlink();
	Node *tmp2Llink = tmp2->getLlink();
	Node *tmp2Rlink = tmp2->getRlink();

	if (tmp1 == tmp2) {
		return;
	}
	else if (tmp1->getRlink() == tmp2) {
		if (tmp1 == Head) {
			Head = tmp2;
			if (tmp2 != Tail) {
				tmp2Rlink->setLlink(tmp1);
			}
			else {
				Tail = tmp1;
			}
		}
		else if (tmp2 == Tail) {
			Tail = tmp1;
			tmp1Llink->setRlink(tmp2);
		}
		else
		{
			tmp2Rlink->setLlink(tmp1);
			tmp1Llink->setRlink(tmp2);
		}
		tmp1->setRlink(tmp2Rlink);
		tmp2->setLlink(tmp1Llink);

		tmp1->setLlink(tmp2);
		tmp2->setRlink(tmp1);
	}
	else {
		if (tmp1 == Head) {
			Head = tmp2;
			if (tmp2 != Tail) {
				tmp2Rlink->setLlink(tmp1);
			}
			else {
				Tail = tmp1;
			}
		}
		else if (tmp2 == Tail) {
			Tail = tmp1;
			tmp1Llink->setRlink(tmp2);
		}
		else {
			tmp2Rlink->setLlink(tmp1);
			tmp1Llink->setRlink(tmp2);
		}
		tmp1Rlink->setLlink(tmp2);
		tmp2Llink->setRlink(tmp1);

		tmp1->setRlink(tmp2Rlink);
		tmp2->setLlink(tmp1Llink);

		tmp1->setLlink(tmp2Llink);
		tmp2->setRlink(tmp1Rlink);
	}
}

void DoubleList::Reverse()
{
	Node *current = Head;
	while (current != NULL)
	{
		Node *next = current->getRlink();
		current->setRlink(current->getLlink());
		current->setLlink(next);
		if (next == NULL) {
			Tail = Head;
			Head = current;
			break;
		}
		current = next;
	}
}