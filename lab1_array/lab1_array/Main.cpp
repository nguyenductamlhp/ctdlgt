#include "lib.h"
using namespace std;

void main() {

	int A[100];
	int N;
	int X;

	cout << endl << "------------------------BAI 1----------------------" << endl;
	cout << "a. Nhap mang:" << endl;
	InArray(A, N);
	cout << "b. Day vua vua nhap:" << endl;
	OutArray(A, N);
	cout << "c. Co " << countPrime(A, N) << " so nguyen to la: ";
	printPrime(A, N);
	cout << endl << "d. Vi tri so nguyen:" << endl;
	cout << "Nhap so nguyen x: ";
	cin >> X;
	cout << "Vi tri cua so " << X << " la: " << getPos(A, N, X);
	cout << endl << "e. Xoa so Y:" << endl;
	cout << "Nhap so X: ";
	cin >> X;
	deleteByNumber(A, N, X);
	cout << "Mang sau khi xoa:" << endl;
	OutArray(A, N);
	cout << endl << "f. Vi tri co gia tri gan nhat:" << endl;
	cout << "Nhap so nguyen:";
	cin >> X;
	cout << "Vi tri co gia tri gan nhat voi " << X << " la:" << getPosApporoximate(A, N, X);


	cout << endl << "------------------------BAI 2----------------------" << endl;
	cout << "a. Nhap mang:" << endl;
	InArray(A, N);
	cout << "b. Day vua vua nhap:" << endl;
	OutArray(A, N);
	
	
	system("pause");
}