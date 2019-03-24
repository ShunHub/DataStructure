#pragma once

#include<iostream>

using std::endl; using std::cout; using std::cin;


class Node {

public:
	int index;
	int data;
	Node *pLChild;
	Node *pRChild;
	Node *pParent;

	Node() {
		index = 0;
		data = 0;
		pLChild = NULL;
		pRChild = NULL;
		pParent = NULL;
	}

	Node *SearchNode(int nodeIndex) {

		if (this->index == nodeIndex)
			return this;

		Node *temp = NULL;

		if (this->pLChild != NULL) {
			if (this->pLChild->index == nodeIndex)
				return this->pLChild;
			else{
				temp = this->pLChild->SearchNode(nodeIndex);
				if (temp != NULL)
					return temp;
			}
		}

		if (this->pRChild != NULL) {
			if (this->pRChild->index == nodeIndex)
				return this->pRChild;
			else {
				temp = this->pRChild->SearchNode(nodeIndex);
				if (temp != NULL)
					return temp;
			}
		}
		
		return NULL;
	}

	void DeleteNode() {
		if (this->pLChild != NULL)
			this->pLChild->DeleteNode();
		if (this->pRChild != NULL)
			this->pRChild->DeleteNode();
		
		if (this->pParent != NULL) {
			if (this->pParent->pLChild == this)
				this->pParent->pLChild = NULL;
			else if (this->pParent->pRChild == this)
				this->pParent->pRChild = NULL;
		}

		delete this;

	}


	void PreorderTraversal() {

		cout << this->index << "   :   " << this->data << endl;
		if (this->pLChild != NULL)
			this->pLChild->PreorderTraversal();
		if (this->pRChild != NULL)
			this->pRChild->PreorderTraversal();
	}

	void InorderTraversal() {
		if (this->pLChild != NULL)
			this->pLChild->InorderTraversal();

		cout << this->index << "   :   " << this->data << endl;

		if (this->pRChild != NULL)
			this->pRChild->InorderTraversal();
	}

	void PostorderTraversal() {
		if (this->pLChild != NULL)
			this->pLChild->PostorderTraversal();

		if (this->pRChild != NULL)
			this->pRChild->PostorderTraversal();
		cout << this->index << "   :   " << this->data << endl;
	}




};

class Tree {

private:
	Node *m_pRoot;

public:
	Tree() {
		m_pRoot = new Node();
	}

	~Tree() {
		m_pRoot->DeleteNode();
	}


	Node *SearchNode(int nodeIndex) {
		return m_pRoot->SearchNode(nodeIndex);
	}

	bool AddNode(int nodeIndex, int direction, Node *pNode) {

		Node *temp = SearchNode(nodeIndex);
		if (temp == NULL)
			return false;

		Node * node = new Node();
		node->index = pNode->index;
		node->data = pNode->data;
		node->pParent = temp;

		if (direction == 0) {

			temp->pLChild = node;
			return true;

		}
		else if (direction == 1) {
			temp->pRChild = node;
			return true;
		}
		return false;
	}

	bool DeleteNode(int nodeIndex, Node *pNode) {

		Node *temp = SearchNode(nodeIndex);
		if (temp == NULL)
			return false;

		if (pNode != NULL) 
			pNode->data = temp->data;

		temp->DeleteNode();
		return true;

	}


	//前序遍历
	void PreorderTraversal() {
		m_pRoot->PreorderTraversal();
	}

	//中序遍历
	void InorderTraversal() {
		m_pRoot->InorderTraversal();
	}

	//后序遍历
	void PostorderTraversal() {
		m_pRoot->PostorderTraversal();
	}



};





