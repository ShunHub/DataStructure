/*
树的定义：
树是节点的有限集合

完全二叉树的定义：
若设二叉树的深度为h，除第n层外，其它各层（1~h-1）的节点数都达到最大个数，第h层所有的节点都连续集中在最左边，这就是完全二叉树
*/

#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


/*
数组二叉树
.....................................................
父亲节点下标*2+1 = 该节点的左孩子
父亲节点下标*2+2 = 该节点的右孩子
..............................
				3(0)
		5(1)			8(2)
	2(3)	6(4)	9(5)	7(6)
.....................................................
父亲节点下标*2 = 该节点的左孩子
父亲节点下标*2+1 = 该节点的右孩子
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

	//搜索一个节点
	int* SearchNode(int nodeIndex) {

		if (nodeIndex < 0 || nodeIndex >= m_iSize)
			return NULL;

		if (m_pTree[nodeIndex] == 0)
			return NULL;
		return &m_pTree[nodeIndex];
	}

	//插入一个节点
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

	//删除一个节点
	bool DeleteNode(int nodeIndex, int *pNode) {

		if (nodeIndex < 0 || nodeIndex >= m_iSize)
			return false;
		if (m_pTree[nodeIndex] == 0)
			return false;

		*pNode = m_pTree[nodeIndex];
		m_pTree[nodeIndex] = 0;
		return true;
	}

	//遍历
	void TreeTraverse() {

		for (int i = 0; i < m_iSize; i++)
		{
			cout << m_pTree[i] << " ";
		}
		cout << endl;

	}

};











