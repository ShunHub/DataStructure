#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;

class Node {

public:
	int data;
	Node *next;
	void printNode() { cout << data << endl; }
};

class List {

private:
	Node *m_pList;
	int m_iLength;

public:
	List() {

		m_pList = new Node;
		m_pList->data = 0;
		m_pList->next = NULL;
		m_iLength = 0;

	}

	~List() {
		ClearList();
		delete m_pList;
	}

	void ListTraverse() {

		Node *newNode = m_pList;
		for (int i = 0; i < m_iLength; i++)
		{
			newNode = newNode->next;
			newNode->printNode();
		}

	}



	bool ListEmpth() {
		if (m_iLength == 0)
			return true;
		return false;
	}

	int ListLength() {
		return m_iLength;
	}

	void ClearList() {
		
		Node *currentNode = m_pList->next;
		while (currentNode != NULL) {
			Node *temp = currentNode->next;
			delete currentNode;
			currentNode = temp;
		}
		m_pList->next = NULL;

	}

	//在表头前插入
	bool ListInsertHead(Node *pNode) {

		Node *temp = m_pList->next;
		Node *newNode = new Node;

		if (newNode == NULL)
			return false;

		newNode->data = pNode->data;
		m_pList->next = newNode;
		newNode->next = temp;
		m_iLength++;

		return true;
	}

	//在尾部插入节点
	bool ListInsertTail(Node *pNode) {
		Node *currentNode = m_pList;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		Node *newNode = new Node;
		if (newNode == NULL)
			return false;
		
		newNode->data = pNode->data;
		newNode->next = NULL;
		currentNode->next = newNode;
		m_iLength++;
		return true;
	}

	//插入一个节点
	bool ListInsert(int num, Node *pNode) {

		if (num<0 || num>m_iLength)
			return false;

		Node *currentNode = m_pList;
		for (int i = 0; i < num; i++)
		{
			currentNode = currentNode->next;
		}

		Node *newNode = new Node;
		if (newNode == NULL)
			return false;

		newNode->data = pNode->data;
		newNode->next = currentNode->next;
		currentNode->next = newNode;
		m_iLength++;
		return true; 

	}

	//删除一个节点
	bool ListDelete(int num, Node *pNode) {

		if (num < 0 || num >= m_iLength)
			return false;

		Node *currentNode = m_pList;
		Node *currentNodeBefore = NULL;
		for (int i = 0; i <= num; i++)
		{
			currentNodeBefore = currentNode;
			currentNode = currentNode->next;
		}

		currentNodeBefore->next = currentNode->next;
		pNode->data = currentNode->data;
		delete currentNode;
		currentNode = NULL;
		m_iLength--;
		return true;
	}

	//获取一个节点的值
	bool GetElem(int num, Node *pNode) {

		if (num < 0 || num >= m_iLength)
			return false;

		Node *currentNode = m_pList;
		for (int i = 0; i <= num; i++)
		{
			currentNode = currentNode->next;
		}
		pNode->data = currentNode->data;
		return true;

	}

	//获取与pNode第一个相同的元素的位序
	int LocateElem(Node *pNode) {

		Node *currentNode = m_pList;
		int count = 0;

		while (currentNode->next != NULL) {
			currentNode = currentNode->next;
			if (currentNode->data == pNode->data)
				return count;
			count++;
		}
		return -1;

	 }


};
