#pragma once



class MyQueue {

private:
	int *m_pQueue;     //��������ָ��
	int m_iQueueLen;   //����Ԫ�ظ���
	int m_iQueueCapacity;     //������������



public:
	MyQueue(int queueCapacity) {
		m_iQueueCapacity = queueCapacity;
	}


};
