#include "Manager.h"

Manager::Manager()
{
	doublelist = new DoubleList;
	stack = new Stack;
	queue = new Queue;
	tree = new Tree;
}

Manager::~Manager()
{
}

void Manager::Doublerun() {
	int _menu = 0;
	int find = 0;
	int Num = 0;
	int _position = 0;

	while (true) {
		cout << "1.추가 2.삭제 3.출력 4.전체삭제 5.노드 총 갯수\n6.찾기 7.버블정렬 8.삽입정렬 9.퀵정렬 10.링크드 뒤집기\n입력 : ";
		cin >> _menu;

		switch (_menu)
		{
		case INSERT:
			cout << "추가할 정수 : ";
			cin >> Num;
			cout << "위치 입력 : ";
			cin >> _position;
			doublelist->insertNode(Num, _position);
			break;
		case DEL:
			if (doublelist->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				int _location = 0;
				cout << "데이터 삭제할 위치 : ";
				cin >> _location;
				doublelist->delNode(_location);
			}
			break;
		case COUT:
			if (doublelist->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				doublelist->displayNode();
			}
			break;
		case ALLDEL:
			if (doublelist->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				doublelist->AllDel();
			}
			break;
		case COUNTNODE:
			cout << "총 갯수 : " << doublelist->CountNode() << endl;
			break;
		case SEARCH:
			if (doublelist->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				cout << "몇 번째 데이터 : ";
				cin >> find;
				cout << "당신이 찾는 데이터 : " << doublelist->Find(find) << endl << endl;
			}
			break;
		case BUBBLESORT:
			cout << "버블정렬 전 출력 : " << endl;
			doublelist->displayNode();
			doublelist->BubbleSort();
			cout << "버블정렬 후 출력 : " << endl;
			doublelist->displayNode();
			break;
		case INSERTSORT:
			cout << "삽입정렬 전 출력 : " << endl;
			doublelist->displayNode();
			doublelist->InsertSort();
			cout << "삽입정렬 후 출력 : " << endl;
			doublelist->displayNode();
			break;
		case QUICKSORT:
			cout << "퀵정렬 전 출력 : " << endl;
			doublelist->displayNode();
			doublelist->QuickSort(0, doublelist->CountNode() - 1);
			cout << "퀵정렬 후 출력 : " << endl;
			doublelist->displayNode();
			break;
		case REVERSE:
			cout << "뒤집기 전 출력 : " << endl;
			doublelist->displayNode();
			doublelist->Reverse();
			cout << "뒤집기 후 출력 : " << endl;
			doublelist->displayNode();
			break;
		default:
			cout << "다시 입력해주세요" << endl;
			break;
		}
	}
}

void Manager::StackRun() {
	int menu = 0;
	int _data = 0;

	while (true)
	{
		cout << "1.삽입\n2.반환\n3.출력\n입력 : ";
		cin >> menu;

		switch (menu)
		{
		case INSERT:
			cout << "추가 할 데이터 : ";
			cin >> _data;
			stack->Push(_data, 0);
			stack->display();
			break;
		case DEL:
			stack->Pop(0);
			stack->display();
			break;
		case COUT:
			if (stack->getdouble()->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				stack->display();
			}
			break;
		default:
			break;
		}
	}
}

void Manager::QueueRun() {
	int menu = 0;
	int _data = 0;

	while (true)
	{
		cout << "1.삽입\n2.반환\n3.출력\n입력 : ";
		cin >> menu;

		switch (menu)
		{
		case INSERT:
			cout << "추가 할 데이터 : ";
			cin >> _data;
			queue->enqueue(_data, -1);
			queue->display();
			break;
		case DEL:
			queue->dequeue(0);
			queue->display();
			break;
		case COUT:
			if (queue->getdouble()->getHead() == NULL) {
				cout << "데이터가 없습니다." << endl << endl;
			}
			else {
				queue->display();
			}
			break;
		default:
			break;
		}
	}
}

void Manager::TreeRun() {
	int menu = 0;
	int treedata = 0;

	while (true)
	{
		cout << "1.삽입\n2.전체삭제\n3.출력\n입력 : ";
		cin >> menu;

		switch (menu)
		{
		case INSERT:
			cout << "추가할 데이터 : ";
			cin >> treedata;
			tree->createNode(treedata);
			break;
		case DEL:
			tree->delNode(tree->getBinaryTree());
			break;
		case COUT:
			tree->display(tree->getBinaryTree());
			break;
		default:
			break;
		}
	}
}