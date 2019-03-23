#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


class Node {

public:
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;

	Node() {
		index = 0;
		data = 0;
		pLChild = NULL;
		pRChild = NULL;
		pParent = NULL;
	}
};

class Tree {

private:
	Node *m_pRoot;

public:
	Tree() {
		m_pRoot = new Node();
	}
	~Tree() { delete m_pRoot; }



};





