#include <iostream>
using namespace std;

void InArray(int* A, int &n) {
	cout << "Amount of element: ";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = ";
		cin >> A[i];
	}
}

void OutArray(int* A, int n) {
	cout << "Array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "A[" << i << "] = " << A[i] << endl;
	}
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

void InterchangeSort(int* A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (A[i] > A[j]) {
				swap(A[i], A[j]);
			}
		}
	}
}

void SelectionSort(int *A, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (A[min] > A[j]) {
				min = j;
			}
		}
		swap(A[i], A[min]);
	}
}

void InsertionSort(int* A, int n) {
	int pos;
	int x;
	for (int i = 1; i < n; i++) {
		x = A[i];
		pos = i - 1; 
		while (pos > 0 && A[pos] > x) {
			A[pos + 1] = A[pos];
			pos--;
		}
		A[pos + 1] = x;
	}
}

void BubbleSort(int* A, int n) {
	int surface = 0;
	while (surface < n - 1) {
		int j = n - 1;
		while (j > surface) {
			if (A[j] < A[j - 1]) {
				swap(A[j], A[j - 1]);
			}
			j--;
		}
		surface++;
	}	

}


void main() {
	int A[100];
	int n;
	InArray(A, n);
	OutArray(A, n);

	cout << "Interchage sort:" << endl;
	InterchangeSort(A, n);
	OutArray(A, n);

	cout << "Selection sort:" << endl;
	SelectionSort(A, n);
	OutArray(A, n);

	cout << "Insertion sort:" << endl;
	InsertionSort(A, n);
	OutArray(A, n);

	cout << "Bubble sort:" << endl;
	BubbleSort(A, n);
	OutArray(A, n);
	system("pause");
}