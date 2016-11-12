#include "IntegerSingleLinkList.h"

void main() {
	List list;
	InitList(list);
	
	addToHead(list, 1);
	addToHead(list, 2);
	addToHead(list, 3);
	printList(list);
	system("pause");
}