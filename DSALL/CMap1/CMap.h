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
	int m_iCapacity;         //ͼ�����������ɵĶ�����
	int m_iNodeCount;        //�Ѿ���ӵĶ��㣨�ڵ㣩����
	Node *m_pNodeArray;      //������Ŷ�������
	int *m_pMatrix;          //��������ڽӾ���

public:
	CMap(int capacity) {

		m_iCapacity = capacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity * m_iCapacity];

		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));            //�ڴ��趨,��ʼ�� 
	}

	~CMap() {
		delete[] m_pNodeArray;
		delete[] m_pMatrix;
	}

	//��ӽڵ�
	bool addNode(Node *pNode) {

		if (pNode == NULL)
			return false;

		m_pNodeArray[m_iNodeCount].m_cData = pNode->m_cData;
		m_iNodeCount++;
		return true;
	}

	//�����ʱ�ʶ��Ϊfalse
	void resetNode() {

		for (int i = 0; i < m_iNodeCount; i++)
		{
			m_pNodeArray[i].m_bIsVisited = false;
		}

	}

	//������ͼ������ֵ
	bool setValueToMatrixForDirectedGraph(int row, int col, int val=1) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;

		m_pMatrix[row*m_iCapacity + col] = val;
		return true;
	}

	//������ͼ������ֵ
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val=1) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;

		m_pMatrix[row*m_iCapacity + col] = val;
		m_pMatrix[col*m_iCapacity + row] = val;
		return true;
	}

	//���ڽӾ����л�ȡֵ
	bool getValueFromMatrix(int row, int col, int &val) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;
		
		val = m_pMatrix[row * m_iCapacity + col];
		return true;

	}

	//��ӡ����
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

	//������ȱ���
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

	 //������ȱ���
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








