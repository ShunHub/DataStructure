#include<iostream>

#include"Vector.h"

using std::cout; using std::cin; using std::endl;


int main(int argc, char **argv) {

	int e0 = 3; int e1 = 5; int e2 = 7; int e3 = 2; int e4 = 9; int e5 = 1; int e6 = 8; int temp = 0;
	Vector *vector = new Vector(10);

	vector->ListInsert(0, &e0);
	vector->ListInsert(1, &e1);
	vector->ListInsert(2, &e2);
	vector->ListInsert(3, &e3);
	vector->ListInsert(4, &e4);
	vector->ListInsert(5, &e5);
	vector->ListInsert(6, &e6);

	vector->ListDelete(0, &temp);

	vector->ListTraverse();
	cout << "#" << temp << endl;
	delete vector;

	cin.get();
	return 0;

}