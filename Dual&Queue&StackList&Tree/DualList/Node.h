#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	Node *Llink;
	Node *Rlink;

	int IDNode;
	int Data;
public:
	Node();
	~Node();

	
	Node *getLlink() { return Llink; }
	Node *getRlink() { return Rlink; }

	void setLlink(Node *llink) { Llink = llink; }
	void setRlink(Node *rlink) { Rlink = rlink; }

	int getData() { return Data; }
	void setData(int _Data) { Data = _Data; }

	int GetID() { return IDNode; }
	void SetID(int idnum) { IDNode = idnum; }
};