#include <iostream>

using namespace std;

struct Node {
	int Data;
	Node* Left;
	Node* Right;
};


void initTree(Node* Root) {
	Root = NULL;
}

void printBinaryTreeNLR(Node* Root) {
	if (Root == NULL) {
		return;
	}
	else {
		cout << Root->Data;
		printBinaryTreeNLR(Root->Left);
		printBinaryTreeNLR(Root->Right);
	}
}

void printBinaryTreeLNR(Node* Root) {
	if (Root == NULL) {
		return;
	}
	else {
		printBinaryTreeNLR(Root->Left);
		cout << Root->Data;		
		printBinaryTreeNLR(Root->Right);
	}
}

void printBinaryTreeLRN(Node* Root) {
	if (Root == NULL) {
		return;
	}
	else {
		printBinaryTreeNLR(Root->Left);		
		printBinaryTreeNLR(Root->Right);
		cout << Root->Data;
	}
}

bool isExist(Node* Root, int x) {
	if (Root == NULL) {
		return;
	}
	else {
		if (x == Root->Data) {
			return true;
		}
		else if (x < Root->Data) {
			isExist(Root->Left, x);
		}
		else if (x > Root->Data) {
			isExist(Root->Right, x);
		}
	}
}

void addNode(Node* &Root, int k) {
	if (Root == NULL) {
		Node* node = new Node;
		node->Data = k;
		node->Left = NULL;
		node->Right = NULL;
		Root = node;
	}
	else if (Root->Data < k) {
		addNode(Root->Right, k);
	}
	else if (Root->Data > k) {
		addNode(Root->Left, k);
	}
}

Node* getParentNode(Node* Root, int x) {
	if (Root == NULL) {
		return NULL;
	}
	else {
		if (x == Root->Left->Data) {
			return Root;
		}
		else if (Root->Left->Data)
		if (x == Root->Right->Data) {
			return Root;
		}
		if (x > Root->Data) {
			isExist(Root->Right, x);
		}
	}
}

void deleteNode(Node* &Root, int k) {
	if (Root == NULL) {
		return;
	}
	else if (Root->Data == k) {

	}
}