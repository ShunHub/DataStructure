#pragma once
/*
数组链表
定义：1、存在唯一的一个被称作“第一个”的元素
2、存在唯一的一个被称作“最后一个”的元素
3、除第一个之外集合中的每个元素均只有一个前驱
4、除最后一个之外，集合中的每个元素均只有一个后继
*/

#include<iostream>

using std::cout; using std::cin; using std::endl;

class Vector {

private:
	int *m_pList;
	int m_iSize;
	int m_iLength;


public:
	Vector(int size) {
		m_iSize = size;
		m_pList = new int[m_iSize];
		m_iLength = 0;
	}
	~Vector() { delete[]m_pList; m_pList = NULL; }

	//清空线性表
	void ClearList() {
		m_iLength = 0;
	}

	//判断线性表是否为空
	bool ListEmpty() {
		return m_iLength == 0 ? true : false;
	}

	//获得当前线性表的长度
	int ListLength() {
		return m_iLength;
	}

	//获取指定元素
	bool GetElem(int i, int *e) {
		if (i < 0 || i >= m_iLength)
			return false;
		*e = m_pList[i];
		return true;
	}

	//寻找第一个满足e的数据元素的位序
	int LocateElem(int *e) {
		for (int i = 0; i < m_iLength; i++)
		{
			if (m_pList[i] == *e)
				return i;
		}
		return -1;
	}

	//获得指定元素的前驱
	bool PriorElem(int *currentElem, int *preElem) {
		int temp = LocateElem(currentElem);
		if (temp == -1)
			return false;
		else if (temp == 0)
			return false;
		else {
			*preElem = m_pList[temp - 1];
			return true;
		}
	}

	//获得指定元素的后驱
	bool NextElem(int *currentElem, int *nextElem) {
		int temp = LocateElem(currentElem);
		if (temp == -1)
			return false;
		else if (temp == m_iLength - 1)
			return false;
		else {
			*nextElem = m_pList[temp + 1];
			return true;
		}

	}

	//遍历
	void ListTraverse() {

		for (int i = 0; i < m_iLength; i++)
		{
			cout << m_pList[i] << "  ";
		}
		cout << endl;
	}

	//插入元素
	bool ListInsert(int i, int *e) {

		if (i<0 || i>m_iLength)
			return false;

		for (int k = m_iLength - 1; k >= i; k--)
		{
			m_pList[k + 1] = m_pList[k];
		}

		m_pList[i] = *e;
		m_iLength++;
		return true;
	}

	//删除元素
	bool ListDelete(int i, int *e) {

		if (i<0 || i>m_iLength - 1)
			return false;

		*e = m_pList[i];
		for (int k = i; k < m_iLength - 1; k++)
		{
			m_pList[k] = m_pList[k + 1];
		}
		m_iLength--;
		return true;
	}



};



