#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


class MyStack {

private:
	char *m_pBuffer;   //栈空间指针
	int m_iSize;       //栈容量
	int m_iTop;        //栈顶，栈中元素的个数


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

	//判断栈是否为空
	bool stackEmpty() {
		return m_iTop == 0 ? true : false;
	}

	//判断栈是否已满
	bool stackFull() {
		return m_iTop == m_iSize ? true : false;
	}

	//清空栈
	void clearStack() {
		m_iTop = 0;
	}

	//获取当前栈中存在多少个元素
	int stackLength() {
		return m_iTop;
	}

	//入栈
	bool push(char elem) {

		if (stackFull())
			return false;

		m_pBuffer[m_iTop] = elem;
		m_iTop++;
		return true;
	}

	//出栈
	bool pop(char &elem) {

		if (stackEmpty()) 
			return false;

		elem = m_pBuffer[m_iTop - 1];
		m_iTop--;
		return true;
	}

	//遍历
	void stackTraverse() {
		for (int i = 0; i < m_iTop; i++)
		{
			cout << m_pBuffer[i] << " : ";
		}
		cout << endl;
	}


};





