#include<iostream>

#include"Tree.h"

using std::cout; using std::cin; using std::endl;


int main(int argc, char **argv) {

	int root = 3;
	Tree *pTree = new Tree(10,&root);

	int node1 = 5;
	int node2 = 8;
	pTree->AddTree(0, 0, &node1);
	pTree->AddTree(0, 1, &node2);

	int node3 = 2;
	int node4 = 6;
	pTree->AddTree(1, 0, &node3);
	pTree->AddTree(1, 1, &node4);

	int node5 = 9;
	int node6 = 7;
	pTree->AddTree(2, 0, &node5);
	pTree->AddTree(2, 1, &node6);

	int node = 0;
	pTree->DeleteNode(6, &node);
	cout << "node =" << node << endl;

	pTree->TreeTraverse();

	int *p = pTree->SearchNode(2);
	cout <<"node2="<< *p << endl;



	delete pTree;
	cin.get();
	return 0;

}