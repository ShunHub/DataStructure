#pragma once
/*
��������
���壺1������Ψһ��һ������������һ������Ԫ��
2������Ψһ��һ�������������һ������Ԫ��
3������һ��֮�⼯���е�ÿ��Ԫ�ؾ�ֻ��һ��ǰ��
4�������һ��֮�⣬�����е�ÿ��Ԫ�ؾ�ֻ��һ�����
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

	//������Ա�
	void ClearList() {
		m_iLength = 0;
	}

	//�ж����Ա��Ƿ�Ϊ��
	bool ListEmpty() {
		return m_iLength == 0 ? true : false;
	}

	//��õ�ǰ���Ա�ĳ���
	int ListLength() {
		return m_iLength;
	}

	//��ȡָ��Ԫ��
	bool GetElem(int i, int *e) {
		if (i < 0 || i >= m_iLength)
			return false;
		*e = m_pList[i];
		return true;
	}

	//Ѱ�ҵ�һ������e������Ԫ�ص�λ��
	int LocateElem(int *e) {
		for (int i = 0; i < m_iLength; i++)
		{
			if (m_pList[i] == *e)
				return i;
		}
		return -1;
	}

	//���ָ��Ԫ�ص�ǰ��
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

	//���ָ��Ԫ�صĺ���
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

	//����
	void ListTraverse() {

		for (int i = 0; i < m_iLength; i++)
		{
			cout << m_pList[i] << "  ";
		}
		cout << endl;
	}

	//����Ԫ��
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

	//ɾ��Ԫ��
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



