#include "Tree.h"

Tree::Tree() : Count(0), Binarytree(NULL)
{
}

Tree::~Tree()
{
}

void Tree::createNode(int treedata) {
	++Count;
	Node *newNode = new Node;
	newNode->setData(treedata);
	newNode->SetID(Count);
	
	if (newNode->GetID() == 1) {
		Binarytree = newNode;
	}
	FindParentTree(Binarytree, newNode->GetID());
	if (newNode->GetID() != 1) {
		if (newNode->GetID() % 2 == 0) {
			Childtree->setLlink(newNode);
		}
		else {
			Childtree->setRlink(newNode);
		}
	}
}

void Tree::FindParentTree(Node *routeNode, int idNum) {
	if (routeNode == NULL) {
		return;
	}
	if ((int)(idNum / 2) == routeNode->GetID()) {
		Childtree = routeNode;
	}
	FindParentTree(routeNode->getLlink(), idNum);
	FindParentTree(routeNode->getRlink(), idNum);
}

void Tree::delNode(Node *Temp) {
	if (Temp == NULL) {
		cout << "노드가 비었음" << endl;
	}
	else {
		//delNode(&(*Temp)->getLlink());
		//delNode(&(*Temp)->getRlink());

		cout << "ID:" << Temp->GetID() << " Data : " << Temp->getData() << " 삭제" << endl;
		delete Temp;
		Temp = NULL;
	}
}

void Tree::display(Node *routeNode) {
	int _route = 0;
	cout << "탐색방법\n1.전위순회 2.중위순회 3.후위순회\n입력 : ";
	cin >> _route;

	switch (_route)
	{
	case PREORDER:
		PreorderTree(routeNode);
		break;
	case INORDER:
		InorderTree(routeNode);
		break;
	case POSTORDER:
		PostorderTree(routeNode);
		break;
	default:
		break;
	}
}

void Tree::PreorderTree(Node *routeNode) {
	if (routeNode == NULL) {
		return;
	}
	else {
		cout << "ID:" << routeNode->GetID() <<" Data : " << routeNode->getData() << endl;
		PreorderTree(routeNode->getLlink());
		PreorderTree(routeNode->getRlink());
	}
}

void Tree::InorderTree(Node *routeNode) {
	if (routeNode == NULL) {
		return;
	}
	else {
		InorderTree(routeNode->getLlink());
		cout << "Data : " << routeNode->getData() << endl;
		InorderTree(routeNode->getRlink());
	}
}

void Tree::PostorderTree(Node *routeNode) {
	if (routeNode == NULL) {
		return;
	}
	else {
		PostorderTree(routeNode->getLlink());
		PostorderTree(routeNode->getRlink());
		cout << "Data : " << routeNode->getData() << endl;
	}
}