#ifndef MinHeap_
#define MinHeap_

#include <iostream>

using namespace std;

struct MinHeap {
	int Size;
	int MaxSize;
	int* Heap;
};

void initHeap(MinHeap &M, int size) {
	M.MaxSize = size;
	M.Heap = new int[M.MaxSize + 1];
	M.Size = 0;
}

void deleteHeap(MinHeap &M) {
	delete M.Heap;
}

void insertToHeap(MinHeap &M, int x) {
	if (M.Size < M.MaxSize) {
		M.Size++;
		int i = M.Size;
		while (i != 1 && x < M.Heap[i / 2]) {
			M.Heap[i] = M.Heap[i / 2];
			i = i / 2;
		}
		M.Heap[i] = x;
	}
}