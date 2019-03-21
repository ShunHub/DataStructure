#pragma once



class MyQueue {

private:
	int *m_pQueue;     //队列数组指针
	int m_iQueueLen;   //队列元素个数
	int m_iQueueCapacity;     //队列数组容量



public:
	MyQueue(int queueCapacity) {
		m_iQueueCapacity = queueCapacity;
	}


};
