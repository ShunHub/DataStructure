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
	int m_iCapacity;         //图中最多可以容纳的顶点数
	int m_iNodeCount;        //已经添加的顶点（节点）个数
	Node *m_pNodeArray;      //用来存放顶点数组
	int *m_pMatrix;          //用来存放邻接矩阵





};








