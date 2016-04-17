#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ConDuong {
	string TenDuong;
	double ChieuDai;
};

void readFile(string filename, ConDuong cd[], int &n) {
	fstream f;
	f.open(filename, ios_base::in);
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> cd[i].TenDuong;
		f >> cd[i].ChieuDai;
	}
	f.close();
}

void writeFile(char* filename, ConDuong cd[], int n) {
	fstream f;
	f.open(filename, ios_base::out);
	f << n << endl;

	for (int i = 0; i < n; i++) {
		f << cd[i].TenDuong;
		f << cd[i].ChieuDai << endl;
	}
	f.close();
}

void swap(ConDuong &a, ConDuong &b) {
	ConDuong t = a;
	a = b;
	b = t;
}

void sort(ConDuong cd[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i; j < n; j++) {
			if (cd[i].ChieuDai > cd[j].ChieuDai) {
				swap(cd[i], cd[j]);
			}
		}
	}
}

double search(ConDuong cd[], int n, string tenduong) {
	for (int i = 0; i < n; i++) {
		if (cd[i].TenDuong == tenduong) {
			return cd[i].ChieuDai;
		}
	}
	return 0;
}

void main(int argc, char* argv[]) {
	ConDuong cd[100];
	int n;
	char* f = argv[1];
	readFile(f, cd, n);

	string ten;
	double dai;
	while (1) {
		cout << "Nhap ten duong (nhap exit de thoat): ";
		cin >> ten;

		if (ten == "exit") {
			exit(0);
		}
		else {
			dai = search(cd, n, ten);
			if (dai > 0) {
				cout << "Duong " << ten << " dai " << dai << "km" << endl;
			}
			else {
				cout << "Khong tim thay" << endl;;
			}

		}
	}
	
}