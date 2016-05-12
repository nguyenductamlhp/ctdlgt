package sort;

public class BubbleSort {

	public static void BubbleSort(int A[], int nA) {
		int t;
		for (int i = 0; i < nA; i++) {
			for (int j = nA - 1; j > i; j--) {
				if (A[j] < A[j - 1]) {
					t = A[j];
					A[j] = A[j - 1];
					A[j - 1] = t;
				}
			}
		}
	}

	public static void main(String[] args) {
		int A[] = { 4, 1, 2, 0, 22, 7 , 6, 13, 8 };	//Mảng A
		int nA = 9;						
		BubbleSort(A, nA);
		for (int i = 0; i < nA; i++) {
			System.out.print(A[i] + " ");
		}

	}

}
