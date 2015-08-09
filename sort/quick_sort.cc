#include <iostream>
#include "sort_utils.cc"

void quick_sort(int *A, int n);
void quick_sort_helper(int *start, int *end);
int partition(int *start, int *end);
void val_swap(int *x, int *y);
void quick_sort_optimized(int *A, int n);
void quick_sort_optimized_helper(int *start, int *end);

void quick_sort(int *A, int n) {
	quick_sort_helper(A, A+n-1);
}

void quick_sort_optimized(int *A, int n) {
	int* B = new int[n+8];
	for (int i = 0; i < n; i++) {
		B[i] = A[i];
	}
	for (int i = n; i < n + 9; i++) {
		B[i] = INT_MAX;
	}
	quick_sort_optimized_helper(B, B+n-1);
	for (int i = 0; i < n; i++) {
		A[i] = B[i];
	}
}

void quick_sort_optimized_helper(int *start, int *end) {
	int n = end - start;
	if (n == 0) {
		return;
	}
	if (n < 8) {
	    small_sort(start, n);
	    return;
	}
	int p = partition(start, end);
	quick_sort_helper(start, start + p - 1);
	quick_sort_helper(start + p, end);
}

void quick_sort_helper(int *start, int *end) {
	if (end - start > 0) {
		int p = partition(start, end);
		quick_sort_helper(start, start + p - 1);
		quick_sort_helper(start + p, end);
	}
}

int partition(int *start, int *end) {
	int piv = *(end);
	int val = -1;
	for (int* j = start; j < end; j++) {
		if (*j <= piv) {
			val++;
			val_swap((start+val), j);
		}
	}
	val++;
	val_swap((start+val), end);
	return val;
}

void val_swap(int *x, int *y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
}
