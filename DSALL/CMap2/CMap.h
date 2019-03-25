#pragma once

#include<iostream>
#include<vector>

using std::endl; using std::cout; using std::cin;


class Edge {

public:
	int m_iNodeIndexA;
	int m_iNodeIndexB;
	int m_iWeightValue;

	bool m_bSelected;

	Edge(int nodeIndexA=0, int nodeIndexB=0, int weightValue = 0) {
		m_iNodeIndexA = nodeIndexA;
		m_iNodeIndexB = nodeIndexB;
		m_iWeightValue = weightValue;
		m_bSelected = false;
	}
};


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

	Edge *m_pEdge;           //��������С�������ıߣ�ȡ���ڵ�ĸ���������n���ߣ�����n-1����


	int getMinEdge(std::vector<Edge> edgeVec) {

		int	minWeight = 0;
		int edgeIndex = 0;
		int i = 0;
		for (; i < edgeVec.size(); i++)
		{
			if (!edgeVec[i].m_bSelected) {
				minWeight = edgeVec[i].m_iWeightValue;
				edgeIndex = i;
				break;
			}
		}

		if (minWeight == 0)
			return -1;

		for (; i < edgeVec.size(); i++)
		{
			if (edgeVec[i].m_bSelected)
				continue;
			else {
				if (minWeight > edgeVec[i].m_iWeightValue) {
					minWeight = edgeVec[i].m_iWeightValue;
					edgeIndex = i;
				}
			}
		}
		
		return edgeIndex;
	}

public:
	CMap(int capacity) {

		m_iCapacity = capacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity * m_iCapacity];

		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));            //�ڴ��趨,��ʼ�� 

		m_pEdge = new Edge[m_iCapacity - 1];
	}

	~CMap() {
		delete[] m_pNodeArray;
		delete[] m_pMatrix;
	}

	//����ķ������
	void primTree(int nodeIndex) {
		int value = 0;       //����ȡ�ߣ��ѱߵ�Ȩֵ���浽value��
		int edgeCount = 0;        //��������ȡ���ߵĸ������ߵļ�����
		std::vector<int> nodeVec;
		std::vector<Edge> edgeVec;

		cout << m_pNodeArray[nodeIndex].m_cData << endl;

		nodeVec.push_back(nodeIndex);
		m_pNodeArray[nodeIndex].m_bIsVisited = true;

		//
		while (edgeCount < m_iCapacity - 1) {

			int temp = nodeVec.back();

			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(temp, i, value);
				if (value != 0) {
					if (m_pNodeArray[i].m_bIsVisited)
						continue;
					else {
						Edge edge(temp, i, value);
						edgeVec.push_back(edge);
					}
				}
			}

			//�ӿ�ѡ�߼������ҳ���С�ı�
			int edgeIndex = getMinEdge(edgeVec);
			edgeVec[edgeIndex].m_bSelected = true;

			cout << edgeVec[edgeIndex].m_iNodeIndexA << "----" << edgeVec[edgeIndex].m_iNodeIndexB << " ";
			cout << edgeVec[edgeIndex].m_iWeightValue << endl;

			m_pEdge[edgeCount] = edgeVec[edgeIndex];
			edgeCount++;

			int nextNodeIndex = edgeVec[edgeIndex].m_iNodeIndexB;
			nodeVec.push_back(nextNodeIndex);
			m_pNodeArray[nextNodeIndex].m_bIsVisited = true;

			cout << m_pNodeArray[nextNodeIndex].m_cData << endl;
		}

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
	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1) {

		if (row < 0 || row >= m_iCapacity || col<0 || col >= m_iCapacity)
			return false;

		m_pMatrix[row*m_iCapacity + col] = val;
		return true;
	}

	//������ͼ������ֵ
	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1) {

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


