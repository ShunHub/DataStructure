#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;

class MyQueue {

private:
	int *m_pQueue;     //队列数组指针
	int m_iQueueLen;   //队列元素个数
	int m_iQueueCapacity;     //队列数组容量
	int m_iHead;     //队头
	int m_iTail;     //队尾


public:
	MyQueue(int queueCapacity) {
		m_iQueueCapacity = queueCapacity;
		m_iHead = 0;
		m_iTail = 0;
		m_iQueueLen = 0;
		m_pQueue = new int[m_iQueueCapacity];
	}

	~MyQueue() { delete[] m_pQueue; }

	//清空队列
	void ClearQueue() {
		m_iHead = 0;
		m_iTail = 0;
		m_iQueueLen = 0;
	}

	//判断队列是否为空
	bool QueueEmpty()const {
		return m_iQueueLen == 0 ? true : false;
	}

	//获取队列长度
	int QueueLength()const {
		return m_iQueueLen;
	}

	//判断队列是否为满
	bool QueueFull()const {
		return m_iQueueLen == m_iQueueCapacity ? true : false;
	}

	//入队
	bool EnQueue(int element) {
		
		if (QueueFull())
			return false;

		m_pQueue[m_iTail] = element;
		m_iTail++;

		m_iTail = m_iTail % m_iQueueCapacity;

		m_iQueueLen++;
		return true;

	}

	//出队
	bool DeQueue(int &element) {

		if (QueueEmpty())
			return false;

		element = m_pQueue[m_iHead];
		m_iHead++;

		m_iHead = m_iHead % m_iQueueCapacity;

		m_iQueueLen--;
		return true;

	}

	//遍历
	void QueueTraverse() {
		for (int i = m_iHead; i < m_iHead+m_iQueueLen; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity] << endl;
		}
	}


};
