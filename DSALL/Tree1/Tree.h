/*
���Ķ��壺
���ǽڵ�����޼���

��ȫ�������Ķ��壺
��������������Ϊh������n���⣬�������㣨1~h-1���Ľڵ������ﵽ����������h�����еĽڵ㶼��������������ߣ��������ȫ������
*/

#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


/*
���������
.....................................................
���׽ڵ��±�*2+1 = �ýڵ������
���׽ڵ��±�*2+2 = �ýڵ���Һ���
..............................
				3(0)
		5(1)			8(2)
	2(3)	6(4)	9(5)	7(6)
.....................................................
���׽ڵ��±�*2 = �ýڵ������
���׽ڵ��±�*2+1 = �ýڵ���Һ���
...............................
				3(1)
		5(2)			8(3)
	2(4)	6(5)	9(6)	7(7)
.....................................................
*/

class Tree {

private:
	int *m_pTree;
	int m_iSize;

public:
	Tree(int size, int *pRoot) {
		m_iSize = size;
		m_pTree = new int[size];
		for (int i = 0; i < size; i++)
		{
			m_pTree[i] = 0;
		}
		m_pTree[0] = *pRoot;
	}
	~Tree() { delete[]m_pTree; }

	//����һ���ڵ�
	int* SearchNode(int nodeIndex) {

		if (nodeIndex < 0 || nodeIndex >= m_iSize)
			return NULL;

		if (m_pTree[nodeIndex] == 0)
			return NULL;
		return &m_pTree[nodeIndex];
	}

	//����һ���ڵ�
	bool AddTree(int nodeIndex, int direction, int *pNode) {
		if (nodeIndex < 0 || nodeIndex >= m_iSize)
			return false;
		if (m_pTree[nodeIndex] == 0)
			return false;

		if (direction == 0) {
			int temp = nodeIndex * 2 + 1;
			if (temp >= m_iSize)
				return false;

			m_pTree[temp] = *pNode;
		}
		else if (direction == 1) {
			int temp = nodeIndex * 2 + 2;
			if (temp >= m_iSize)
				return false;

			m_pTree[temp] = *pNode;
		}
		else
			return false;
	}

	//ɾ��һ���ڵ�
	bool DeleteNode(int nodeIndex, int *pNode) {

		if (nodeIndex < 0 || nodeIndex >= m_iSize)
			return false;
		if (m_pTree[nodeIndex] == 0)
			return false;

		*pNode = m_pTree[nodeIndex];
		m_pTree[nodeIndex] = 0;
		return true;
	}

	//����
	void TreeTraverse() {

		for (int i = 0; i < m_iSize; i++)
		{
			cout << m_pTree[i] << " ";
		}
		cout << endl;

	}

};











