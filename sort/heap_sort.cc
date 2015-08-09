#include <iostream>

using namespace std;

void bubble_up(int *heap, int cur_index) {
    if (cur_index == 0) return;
    int parent_val = heap[(cur_index-1)/2];
    int cur_val = heap[cur_index];
    if (cur_val < parent_val) {
	heap[(cur_index-1)/2] = cur_val;
	heap[cur_index] = parent_val;
	bubble_up(heap, (cur_index-1)/2);
    }
}

void bubble_down(int *heap, int cur_index, int n_elements) {
    int c1_val, c2_val, cur_val;
    if (cur_index*2+1 >= n_elements-1) {
	if (cur_index*2 +1 == n_elements-1) {
	    c1_val = heap[cur_index*2+1];
	    if (c1_val < heap[cur_index]) {
		heap[cur_index+2+1] = heap[cur_index];
		heap[cur_index] = c1_val;
	    }
	}
	return;
    }

    c1_val = heap[cur_index*2+1], c2_val = heap[cur_index*2+2], cur_val = heap[cur_index];
    if (c1_val < cur_val || c2_val < cur_val) {
	if (c1_val > c2_val) {
	    heap[cur_index*2+2] = cur_val;
	    heap[cur_index] = c2_val;
	    bubble_down(heap, cur_index*2+2, n_elements);
	}
	else {
	    heap[cur_index*2+1] = cur_val;
	    heap[cur_index] = c1_val;
	    bubble_down(heap, cur_index*2+1, n_elements);
	}
    }
}

void insert_to_heap(int *heap, int n_elements, int val) {
    heap[n_elements] = val;
    bubble_up(heap, n_elements);
}

int extract_from_heap(int *heap, int n_elements) {
    int top = heap[0];
    heap[0] = heap[n_elements-1];
    bubble_down(heap, 0, n_elements);
    return top;
}

void heapify(int *out, int *values, int n_values) {
    for (int i = 0; i < n_values; i++) {
	insert_to_heap(out, i, values[i]);
    }
}

void heap_sort(int *A, int n) {
    int *B = new int[n];
    heapify(B, A, n);
    for (int i = 0; i < n; i++) {
	A[i] = extract_from_heap(B, n-i);
    }
    delete [] B;
}
