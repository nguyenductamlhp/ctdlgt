#include <iostream>
using namespace std;

int LinearSearch(int A[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (A[i] == key) {
			return i;
		}
	}
	return -1;
}



void main() {
	int A[] = { 2, 4, 21, 55, 24, 46, 86, 44 };
	int n = 8;
	int key = 46;
	if (LinearSearch(A, n, key) != -1) {
		cout << "vi tri can tim la :" << LinearSearch(A, n, key);
	}
	else {
		cout << "Khong tim thay";
	}
	system("pause");
}