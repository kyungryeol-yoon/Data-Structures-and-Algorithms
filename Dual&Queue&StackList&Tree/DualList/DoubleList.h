#pragma once
#include "Node.h"

class DoubleList
{
private:
	Node *Head;
	Node *Tail;
	int IDCount;
public:
	DoubleList();
	~DoubleList();

	Node *getHead() { return Head; }
	Node *getTail() { return Tail; }

	Node *ArrangeNode(int pos);

	void insertNode(int _data, int _location); //삽입 추가 (위치 입력 가능)
	void delNode(int _location); //삭제 (위치 입력 가능)
	void displayNode(); //출력
	void AllDel(); //모두 삭제
	int CountNode(); //현재 노드 갯수
	int Find(int _location); //위치를 찾아 노드 데이터 찾기

	// Sort 알고리즘
	void BubbleSort();
	void InsertSort();
	void QuickSort(int Left, int Right);
	int Partition(int Left, int Right);
	void Swap(Node *tmp1, Node *tmp2);

	void Reverse();
};

