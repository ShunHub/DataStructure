#include<iostream>

#include"Stack.h"

using std::cout; using std::cin; using std::endl;


int main(int argc, char **argv) {

	MyStack *pStack = new MyStack(5);

	pStack->push('h');
	pStack->push('e');
	pStack->push('l');
	pStack->push('l');
	pStack->push('o');


	pStack->stackTraverse();

	char elem = NULL;
	pStack->pop(elem);
	pStack->stackTraverse();


	delete pStack;

	cin.get();
	return 0;

}