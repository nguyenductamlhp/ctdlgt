#include <iostream>
#include <string>

using namespace std;

struct Node {
	string Word;
	string Mean;
	char Balance;
	Node* Left;
	Node* Right;
};

int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
	
}

int getHigh(Node* N) {
	if (N == NULL) {
		return 0;
	}
	else if (N->Left == NULL && N->Right == NULL) {
		return 1;
	}
	else {
		return max(getHigh(N->Left), getHigh(N->Right)) + 1;
	}
}

void init(Node* Root) {
	Root = NULL;
}

void balance(Node* &Root) {

}

void addNode(Node* &Root, Node N) {
	if (Root == NULL) {
		Root = &N;
	}
	else if (Root->Word > N.Word) {
		addNode(Root->Left, N);
	}
	else if (Root->Word < N.Word) {
		addNode(Root->Right, N);
	}
}

