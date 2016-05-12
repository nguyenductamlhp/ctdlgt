package sort;

public class InsertionSort {

	private static void InsertionSort(int A[], int nA) {
		int x;	//Để lưu phần tử đang sắp xếp
		int k;
		for (int i = 1; i < nA; i++) {
			x = A[i];
			k = i - 1;
			while ((k >= 0) && (A[k]) > x) {
				A[k + 1] = A[k];
				k--;
			}
			A[k + 1] = x;
		}
	}
	
	public static void main(String[] args) {
		int A[] = { 4, 1, 2, 0, 22, 7 , 6, 13, 8 };	//Mảng A
		int nA = 9;									//Biến nA lượng số phần tử mảng A
		InsertionSort(A, nA);
		for (int i = 0; i < nA; i++) {
			System.out.print(A[i] + " ");
		}
	}

}
