#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


class MyStack {

private:
	char *m_pBuffer;   //ջ�ռ�ָ��
	int m_iSize;       //ջ����
	int m_iTop;        //ջ����ջ��Ԫ�صĸ���


public:
	MyStack(int size) {

		m_iSize = size;
		m_pBuffer = new char[size];
		m_iTop = 0;

	}

	~MyStack() {
		delete[] m_pBuffer;
		m_pBuffer = NULL;
	}

	//�ж�ջ�Ƿ�Ϊ��
	bool stackEmpty() {
		return m_iTop == 0 ? true : false;
	}

	//�ж�ջ�Ƿ�����
	bool stackFull() {
		return m_iTop == m_iSize ? true : false;
	}

	//���ջ
	void clearStack() {
		m_iTop = 0;
	}

	//��ȡ��ǰջ�д��ڶ��ٸ�Ԫ��
	int stackLength() {
		return m_iTop;
	}

	//��ջ
	bool push(char elem) {

		if (stackFull())
			return false;

		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		return true;
	}

	//��ջ
	bool pop(char &elem) {

		if (stackEmpty()) 
			return false;

		elem = m_pBuffer[m_iTop - 1];
		m_iTop--;
		return true;
	}

	//����
	void stackTraverse() {
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << " : ";
		}
		cout << endl;
	}


};





