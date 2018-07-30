#pragma once

class CSLL
{
private:
	class Node {
	private:
		int m_data;
		Node* m_Rlink;
		Node* m_Llink;
	public:
		int GetData() { return m_data; }
		void SetData(int _data) { m_data = _data; }

		Node *getLlink() { return m_Llink; }
		Node *getRlink() { return m_Rlink; }

		void setLlink(Node* _llink) { m_Llink = _llink; }
		void setRlink(Node* _rlink) { m_Rlink = _rlink; }
	};
private:
	int m_Count;
	Node* m_Head = new Node;
public:
	CSLL();
	~CSLL();
public:
	void InsertNode(int _data, int _location);
	void DelNode(int _location);
	void Print();
	void Delete();
	void CountNode();
	void FindNode();
};

