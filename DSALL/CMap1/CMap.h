#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


class Node {

public:
	char m_cData;
	bool m_bIsVisited;


	Node(char data = 0) {
		m_cData = data;
		m_bIsVisited;
	}

};


class CMap {

private:
	int m_iCapacity;         //ͼ�����������ɵĶ�����
	int m_iNodeCount;        //�Ѿ���ӵĶ��㣨�ڵ㣩����
	Node *m_pNodeArray;      //������Ŷ�������
	int *m_pMatrix;          //��������ڽӾ���





};








