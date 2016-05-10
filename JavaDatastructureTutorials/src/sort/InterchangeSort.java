package sort;

public class InterchangeSort {

	
	private static void InterchangeSort(int A[], int nA) {
		int t;
		for (int i = 0; i < nA - 1; i++) {
			for (int j = i; j < nA; j++) {
				if (A[i] > A[j]) {
					t = A[i];
					A[i] = A[j];
					A[j] = t;
				}
			}
		}
	}
	
	public static void main(String[] args) {
		
		int A[] = { 4, 1, 2, 0, 22, 7 , 6, 13, 8 };	//Mảng A
		int nA = 9;									//Biến nA lư số phần tử mảng A
		InterchangeSort(A, nA);
		for (int i = 0; i < nA; i++) {
			System.out.print(A[i] + " ");
		}
	}

}
