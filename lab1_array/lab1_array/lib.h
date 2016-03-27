#include <iostream>
using namespace std;

void InArray(int A[100], int &n) {
	cout << "Size of array: ";
	cin >> n;
	if (n < 0) {
		n = 0;
	}
	else if (n > 100) {
		n = 100;
	}
	for (int i = 0; i < n; i++) {
		cout << "Arr[" << i << "] = ";
		cin >> A[i];
	}

}

void OutArray(int A[], int n) {
	cout << "Array: " << endl;
	for (int i = 0; i < n; i++) {
		cout << "Arr[" << i << "] = " << A[i] << endl;
	}
}

void swap(int &a, int &b) {
	int t = a;
	a = b;
	b = t;
}

//Excercise 1----------------------------

bool isPrime(int N) {
	if (N < 2) {
		return false;
	}
	for (int i = 2; i < N / 2 + 1; i++) {
		if ((N % i) == 0) {
			return false;
		}
	}
	return true;
}

int countPrime(int A[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (isPrime(A[i])) {
			count++;
		}
	}
	return count;
}

void printPrime(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (isPrime(A[i])) {
			cout << A[i] << "\t";
		}
	}
}

int getPos(int A[], int n, int k) {
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (A[i] == k) {
			pos = i;
		}
	}
	return pos;
}

void deleteByPos(int A[], int &n, int pos) {
	if (pos > n || n < 1) {
		cout << "ERROR";
		exit(0);
	}
	else {
		for (int i = pos; i < n; i++) {
			A[i] = A[i + 1];
		}
		n--;
	}
}

void deleteByNumber(int A[], int &n, int k) {
	while (getPos(A, n, k) != -1) {
		deleteByPos(A, n, getPos(A, n, k));
	}
}

int getPosApporoximate(int A[], int n, int k) {
	int pos = -1;
	int ab = abs(A[0] - k);
	for (int i = 1; i < n; i++) {
		if (abs(A[i] - k) < ab) {
			pos = i;
		}
	}
	return pos;
}
//Excercise 2----------------------------
//Excercise 3----------------------------
int getMinLocation(int* A, int N) {
	int min = 0;
	for (int i = 1; i < N; i++) {
		if (A[min] > A[i]) {
			min = i;
		}
	}
	return min;
}

int getMaxNegativeNumberLocation(int* A, int N) {
	int max = -1;
	for (int i = 1; i < N; i++) {
		if (A[i] < 0) {
			if (A[max] > A[i]) {
				max = i;
			}
		}
	}
	return max;
}

void getSmaller(int* A, int N) {
	if (A[0] < A[1]) {
		cout << A[0] << "\t";
	}
	for (int i = 1; i < N - 1; i++) {
		if (A[i] < A[i - 1] && A[i] < A[i + 1]) {
			cout << A[i] << "\t";
		}
	}
	if (A[N] < A[N - 1]) {
		cout << A[N] << "\t";
	}
}

void Pytago(int* A, int N) {

}
//Excercise 4----------------------------
bool isInArray(int* A, int n, int k) {
	for (int i = 0; i < n; i++) {
		if (A[i] == k) {
			return true;
		}
	}
	return false;
}

void deleteFromPos(int* A, int &n, int pos) {
	n = n - pos - 1;
}

int countDifferentElement(int* A, int n) {
	int B[100];
	B[0] = A[0];
	int nB = 1;
	for (int i = 1; i < n; i++) {
		if (!isInArray(B, nB, A[i])) {
			B[nB] = A[i];
			nB++;
		}
	}
	return nB;
}



int getSecondMax(int* A, int n) {

	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++){
			if (A[i] < A[j]) {
				swap(A[i], A[j]);
			}
		}
	}
	return A[1];
}

void revertArray(int* A, int n) {
	for (int i = 0; i < n / 2; i++) {
		swap(A[i], A[n - 1 - i]);
	}
}



//Excercise 5----------------------------