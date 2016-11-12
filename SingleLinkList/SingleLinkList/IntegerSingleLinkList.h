#include <iostream>

using namespace std;

struct Node {
	int Data; 
	Node* Next;
};

struct List {
	Node* Head;
	Node* Tail;
};

void InitList(List &list) {
	list.Head = NULL;
	list.Tail = NULL;
}

void printList(List list) {
	Node* p = new Node;
	p = list.Head;
	while (p != NULL) {
		cout << p->Data << " ";
		p = p->Next;
	}
}

void addToHead(List &list, int num) {
	Node *p = new Node;
	p->Data = num;
	p->Next = NULL;

	if (list.Head == NULL) {
		list.Head = p;
		list.Tail = p;
	}
	else {
		p->Next = list.Head;
		list.Head = p;
	}
}

