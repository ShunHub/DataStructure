#pragma once

#include<iostream>
#include<vector>

using std::endl; using std::cout; using std::cin;


class Node {

public:
	char m_cData;
	bool m_bIsVisited;


	Node(char data = 0) {
		m_cData = data;
		m_bIsVisited = false;
	}

};


class CMap {

private:
	int m_iCapacity;         //图中最多可以容纳的顶点数
	int m_iNodeCount;        //已经添加的顶点（节点）个数
	Node *m_pNodeArray;      //用来存放顶点数组
	int *m_pMatrix;          //用来存放邻接矩阵

public:
	CMap(int capacity) {

		m_iCapacity = capacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity * m_iCapacity];

		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));            //内存设定,初始化 
	}

	~CMap() {
		delete[] m_pNodeArray;
		delete[] m_pMatrix;
	}

	//添加节点
	bool addNode(Node *pNode) {

		if (pNode == NULL)
			return false;

		m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
		m_iNodeCount++;
		return true;
	}

	//将访问标识置为false
	void resetNode() {

		for (int i = 0; i < m_iNodeCount; i++)
		{
			m_pNodeArray[i].m_bIsVisited = false;
		}

	}

	//向有向图中设置值
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;

		m_pMatrix[row*m_iCapacity + col] = val;
		return true;
	}

	//向无向图中设置值
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;

		m_pMatrix[row*m_iCapacity + col] = val;
		m_pMatrix[col*m_iCapacity + row] = val;
		return true;
	}

	//从邻接矩阵当中获取值
	bool getValueFromMatrix(int row, int col, int &val) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;
		
		val = m_pMatrix[row * m_iCapacity + col];
		return true;

	}

	//打印矩阵
	void printMatrix() {

		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int k = 0; k < m_iCapacity; k++)
			{
				cout << m_pMatrix[i * m_iCapacity + k] << " ";
			}
			cout << endl;
		}


	 }

	//深度优先遍历
	void depthFirstTraverse(int nodeIndex) {

		int value = 0;

		cout << m_pNodeArray[nodeIndex].m_cData << " ";
		m_pNodeArray[nodeIndex].m_bIsVisited = true;

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(nodeIndex, i, value);
			if (value == 1)
			{
				if (m_pNodeArray[i].m_bIsVisited)
					continue;
				else
					depthFirstTraverse(i);
			}
			else
				continue;
		}

	 }

	 //广度优先遍历
	void breadthFirstTraverse(int nodeIndex) {

		cout << m_pNodeArray[nodeIndex].m_cData << " ";
		m_pNodeArray[nodeIndex].m_bIsVisited = true;

		std::vector<int> curVec;
		curVec.push_back(nodeIndex);

		breadFirstTraverseImpl(curVec);

	 }

	void breadFirstTraverseImpl(std::vector<int> preVec) {

		int value = 0;

		std::vector<int> curVec;

		for (int j = 0; j < (int)preVec.size(); j++)
		{
			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(preVec[j], i, value);
				if (value != 0) {

					if (m_pNodeArray[i].m_bIsVisited)
						continue;
					else {
						cout << m_pNodeArray[i].m_cData << " ";
						m_pNodeArray[i].m_bIsVisited = true;
						curVec.push_back(i);
					}

				}

			}
		}

		if (curVec.size() == 0)
			return;
		else {
			breadFirstTraverseImpl(curVec);
		}


	}








};








