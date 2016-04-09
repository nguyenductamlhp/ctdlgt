#include <iostream>
#include <stack>
#include <fstream>
#include <string>
#include "ConDuong.h"
using namespace std;

void swap(ConDuong &a, ConDuong &b) {
	ConDuong t = a;
	a = b;
	b = t;
}

void readFile(string FileName, int &n, ConDuong *listCD) {
	fstream f;
	f.open(FileName, ios_base::in);

	int bd;
	int kt;
	double dai;

	f >> n;
	for (int i = 0; i < n; i++) {
		f >> bd;
		f >> kt;
		f >> dai;
		listCD[i].setDiemBatDau(bd);
		listCD[i].setDiemKetThuc(kt);
		listCD[i].setChieuDai(dai);
	}
	f.close();
	
}

void writeFile(string FileName, int n, ConDuong* listCD) {
	fstream f;
	f.open(FileName, ios_base::out);
	f << n;
	for (int i = 0; i < n; i++) {
		f << listCD[i].getDiemBatDau();
		f << listCD[i].getDiemKetThuc();
		f << listCD[i].getChieuDai() << endl;
	}
	f.close();
}


//*****************1***************************
void SelectionSort(ConDuong *&A, int n) {
	for (int i = 0; i < n - 1; i++) {
		int min = i;
		for (int j = i; j < n; j++) {
			if (A[min].getChieuDai() > A[j].getChieuDai()) {
				min = j;
			}
		}
		swap(A[i], A[min]);
	}
}


//*****************2***************************
void InsertionSort(ConDuong* &A, int n) {
	int pos;
	double x;
	for (int i = 1; i < n; i++) {
		x = A[i].getChieuDai();
		pos = i - 1; 
		while (pos > 0 && A[pos].getChieuDai() > x) {
			A[pos + 1] = A[pos];
			pos--;
		}
		A[pos + 1].setChieuDai(x);
	}
}
//*****************3***************************
void InterchangeSort(ConDuong* &A, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (A[i].getChieuDai() > A[j].getChieuDai()) {
				swap(A[i], A[j]);
			}
		}
	}
}
//*****************4***************************
void BubbleSort(ConDuong* &A, int n) {
	int surface = 0;
	while (surface < n - 1) {
		int j = n - 1;
		while (j > surface) {
			if (A[j].getChieuDai() < A[j - 1].getChieuDai()) {
				swap(A[j], A[j - 1]);
			}
			j--;
		}
		surface++;
	}	

}
//*****************5***************************
void  ShakerSort() {
	cout << "chua thuc hien";
}
//*****************6***************************
void ShellSort(ConDuong* &A, int n) {
	register int i, j, hCnt, h;
	int increment[20], k;
	
	for (h = 1, i = 0; h < n; i++) {
		increment[i] = h;
		h = 3 * h + 1;
	}

	for (i--; i >= 0; i--) {
		h = increment[i];

		for (hCnt = h; hCnt < 2 * h; hCnt++) {
			for (j = hCnt; j < n;) {
				double temp = A[i].getChieuDai();
				k = j;
				while (k - h >= 0 && temp < A[k - h].getChieuDai()){
					A[k] = A[k - h];
					k = k - h;
				}
				A[k].setChieuDai(temp);
				j = j + h;
			}
		}
	}
}
//*****************7***************************
void QuickSort(ConDuong* &A, int left, int right) {
	int i, j;
	double x;
	x = A[(left + right) / 2].getChieuDai();
	i = left;
	j = right;
	do {
		while (A[i].getChieuDai() < x) {
			i++;
		}
		while (A[j].getChieuDai() > x) {
			j--;
		}
		if (i <= j) {
			swap(A[i], A[j]);
			i++;
			j--;
		}
	} while (i < j);
	if (left < j) {
		QuickSort(A, left, j);
	}
	if (i < right) {
		QuickSort(A, i, right);
	}
}
//*****************8***************************
void MergeArray(ConDuong *&A, int left, int right, int mid) {
	int i, j, k;
	ConDuong c[50];
	i = left;
	k = left;
	j = mid + 1;
	while (i < mid && j < right) {
		if (A[i].getChieuDai() < A[j].getChieuDai()) {
			c[k] = A[i];
			k++;
			i++;
		}
		else {
			c[k] = A[j];
			k++;
			j++;
		}
	}
	while (i <= mid) {
		c[k] = A[i];
		k++;
		i++;
	}
	while (j <= right) {
		c[k] = A[j];
		k++;
		j++;
	}
	for (i = left; i < k; i++) {
		A[i] = c[i];
	}
}
void MergeSort(ConDuong *&A, int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {		
		MergeSort(A, left, right);
		MergeSort(A, mid + 1, right);
		MergeArray(A, left, right, mid);
	}
	
}
//*****************9***************************
void heapify(ConDuong A[], int n, int root) {
	int largest = root;
	int left = 2 * root + 1;  
	int right = 2 * root + 2; 

	if (left < n && A[left].getChieuDai() > A[largest].getChieuDai()) {
		largest = left;
	}
	
	if (right < n && A[right].getChieuDai() > A[largest].getChieuDai()){
		largest = right;
	}
	
	if (largest != root) {
		swap(A[root], A[largest]);

		heapify(A, n, largest);
	}
}

void HeapSort(ConDuong A[], int n)
{
	
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(A, n, i);
	}	
	for (int i = n - 1; i >= 0; i--) {	
		swap(A[0], A[i]);	
		heapify(A, i, 0);
	}
}

void main(int argc, char* argv[]) {
	if (argc == 4) {

		int algo = atoi(argv[1]);
		string fin = argv[2];
		string fout = argv[3];
		
		int n = -1;
		ConDuong *listCD = new ConDuong[n];
		readFile(fin, n, listCD);

		switch (algo) {
		case 1:
			SelectionSort(listCD, n);
			writeFile(fout, n, listCD);
			break;
		case 2:
			InsertionSort(listCD, n);
			writeFile(fout, n, listCD);
			break;
		case 3:
			InterchangeSort(listCD, n);
			writeFile(fout, n, listCD);
			break;
		case 4:
			BubbleSort(listCD, n);
			writeFile(fout, n, listCD);
			break;
		case 5:
			ShakerSort();
			writeFile(fout, 0, listCD);
			break;
		case 6:
			ShellSort(listCD, n);
			writeFile(fout, n, listCD);
			break;
		case 7:
			QuickSort(listCD, 0, n - 1);
			writeFile(fout, n, listCD);
			break;
		case 8:
			MergeSort(listCD, 0, n - 1);
			writeFile(fout, n, listCD);
			break;
		case 9:
			HeapSort(listCD, n);
			writeFile(fout, n, listCD);
			break;

		}
	}
	else {
		cout << "error!";
		system("pause");
	}
}