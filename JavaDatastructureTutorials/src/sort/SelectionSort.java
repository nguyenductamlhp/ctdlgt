package sort;

public class SelectionSort {	

	private static void swap(int A[], int m, int n) {
		int t = A[m];
		A[m] = A[n];
		A[n] = t;
	}
	
	private static void SelectionSort(int A[], int nA) {
		
		for (int j = 0; j < nA - 1; j++) {
			int min = j;
			for (int i = j; i < nA; i++) {
				if (A[i] < A[min]) {
					min = i;
				}
			}
			swap(A, min, j);
		}
		
	}
	public static void main(String[] args) {	//Khai báo hàm main
		int A[] = { 4, 1, 2, 0, 22, 7 , 6, 13, 8 };	//Mảng A
		int nA = 9;									//Biến nA lư số phần tử mảng A
		SelectionSort(A, nA);
		for (int i = 0; i < nA; i++) {
			System.out.print(A[i] + " ");
		}
	}

}
