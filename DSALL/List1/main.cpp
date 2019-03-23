#include<iostream>

#include"List.h"

using std::cout; using std::cin; using std::endl;


int main(int argc, char **argv) {

	List *pList = new List();
	
	Node node0;
	node0.data = 3;
	Node node1;
	node1.data = 4;
	Node node2;
	node2.data = 5;
	Node node3;
	node3.data = 6;
	Node node4;
	node4.data = 7;

	pList->ListInsertHead(&node0);
	pList->ListInsertHead(&node1);
	pList->ListInsertHead(&node2);
	pList->ListInsertHead(&node3);

	pList->ListInsertTail(&node4);

	pList->ListDelete(1, new Node);

	pList->ListTraverse();
	
	delete pList;
	pList = NULL;


	cin.get();
	return 0;

}