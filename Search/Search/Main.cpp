#include <iostream>

using namespace std;

int main() {
	int n = 6;//Số phần tử là 6
	int A[6] = { 2, 4, 26, 9, 11, 78 };// Khởi tạo mảng A
	int x = 26;// Giá trị cần tìm x = 26

	for (int index = 0; index < n; index++) {
		if (index >= n) {//So sánh index và n, đã hết mảng
			cout << "khong tim thay";
			system("pause");
		}
		else {//chưa hết mảng
			if (A[index] == x) {//Tím thấy x
				cout << "vi tri la " << index;//Trả ra vị trí của x
				system("pause");
				return index;
			}			
		}
	}
	return 0;
}