package sort;

public class QuickSort {
	
	private class Sort {
		public Sort() {
			
		}
		public  void QuickSort(int A[], int start, int end) {
			int i, j, x, t;
			i = start;
			j = end;
			x = A[(start + end) / 2];
			do {
				while (A[i] < x) {
					i++;
				}
				while (A[j] > x) {
					j--;
				}
				if (i <= j) {
					t = A[i];
					A[i] = A[j];
					A[j] = t;
				}
			} while (i < j);
			if (start < j) {
				QuickSort(A, start, j);
			}
			if (i < end) {
				QuickSort(A, i, end);
			}
		}

	}
	
	public static void main(String[] args) {
		int A[] = { 4, 1, 2, 0, 22, 7 , 6, 13, 8 };	
		int nA = 9;									
		Sort sort = new Sort();
		sort.QuickSort(A, 0, nA - 1);
		for (int i = 0; i < nA; i++) {
			System.out.print(A[i] + " ");
		}

	}

}
