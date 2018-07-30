#pragma once
#include "Node.h"

enum LINE {
	LEFT = 1,
	RIGHT = 2,
};

enum PRINT {
	PREORDER = 1,
	INORDER = 2,
	POSTORDER = 3,
};

class Tree
{
private:
	int Count;

	Node *Binarytree;
	Node *Childtree;
public:
	Tree();
	~Tree();

	Node *getBinaryTree() { return Binarytree; }
	//Node *getChildTree() { return Childtree; }

	void createNode(int treedata);
	void FindParentTree(Node *routeNode, int idnum);
	void delNode(Node *Temp);
	void display(Node *routeNode);
	void PreorderTree(Node *routeNode);
	void InorderTree(Node *routeNode);
	void PostorderTree(Node *routeNode);
};

