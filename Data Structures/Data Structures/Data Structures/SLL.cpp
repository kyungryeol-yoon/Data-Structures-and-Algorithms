#include "SLL.h"
#include "GlobalHeader.h"

CSLL::CSLL()
{
}


CSLL::~CSLL()
{
}

void CSLL::InsertNode(int _data, int _location)
{
	Node* newNode = new Node;
	newNode->SetData(_data);

	if (m_Head == NULL) {
		m_Head = newNode;
	}
	else {
		
	}
}

void CSLL::DelNode(int _location)
{
}

void CSLL::Print()
{
}

void CSLL::Delete()
{
}

void CSLL::CountNode()
{
}

void CSLL::FindNode()
{
}
