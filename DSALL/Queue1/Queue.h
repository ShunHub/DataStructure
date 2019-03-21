#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;

class MyQueue {

private:
	int *m_pQueue;     //��������ָ��
	int m_iQueueLen;   //����Ԫ�ظ���
	int m_iQueueCapacity;     //������������
	int m_iHead;     //��ͷ
	int m_iTail;     //��β


public:
	MyQueue(int queueCapacity) {
		m_iQueueCapacity = queueCapacity;
		m_iHead = 0;
		m_iTail = 0;
		m_iQueueLen = 0;
		m_pQueue = new int[m_iQueueCapacity];
	}

	~MyQueue() { delete[] m_pQueue; }

	//��ն���
	void ClearQueue() {
		m_iHead = 0;
		m_iTail = 0;
		m_iQueueLen = 0;
	}

	//�ж϶����Ƿ�Ϊ��
	bool QueueEmpty()const {
		return m_iQueueLen == 0 ? true : false;
	}

	//��ȡ���г���
	int QueueLength()const {
		return m_iQueueLen;
	}

	//�ж϶����Ƿ�Ϊ��
	bool QueueFull()const {
		return m_iQueueLen == m_iQueueCapacity ? true : false;
	}

	//���
	bool EnQueue(int element) {
		
		if (QueueFull())
			return false;

		m_pQueue[m_iTail] = element;
		m_iTail++;

		m_iTail = m_iTail % m_iQueueCapacity;

		m_iQueueLen++;
		return true;

	}

	//����
	bool DeQueue(int &element) {

		if (QueueEmpty())
			return false;

		element = m_pQueue[m_iHead];
		m_iHead++;

		m_iHead = m_iHead % m_iQueueCapacity;

		m_iQueueLen--;
		return true;

	}

	//����
	void QueueTraverse() {
		for (int i = m_iHead; i < m_iHead+m_iQueueLen; i++)
		{
			cout << m_pQueue[i%m_iQueueCapacity] << endl;
		}
	}


};
