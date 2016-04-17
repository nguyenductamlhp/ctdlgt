#include <iostream>

using namespace std;

void swap(int &a, int &b) {
	int t = a; 
	a = b;
	b = t;
}

int LomutoPartition(int *A, int left, int right) {
	int pivot = A[right];
	int i = left - 1;
	for (int j = left; j < right; j++) {
		if (A[i] < pivot) {
			i++;
			swap(A[i], A[j]);
		}

	}
	swap(A[i + 1], A[right]);
	return i + 1;
}

void QuickSort(int* A, int left, int right) {
	int t;
	if (left < right) {
		t = LomutoPartition(A, left, right);
		QuickSort(A, left, t - 1);
		QuickSort(A, t + 1, right);
	}
}