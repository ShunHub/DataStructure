#include<iostream>

#include"Queue.h"

using std::cout; using std::cin; using std::endl;


int main(int argc, char **argv) {


	MyQueue *p = new MyQueue(4);

	p->EnQueue(10);
	p->EnQueue(12);
	p->EnQueue(16);
	

	p->QueueTraverse();

	delete p;

	cin.get();
	return 0;

}