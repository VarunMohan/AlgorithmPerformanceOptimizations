#include <iostream>
void quick_sort(int *A, int n);
void quick_sort_helper(int *start, int *end);
int partition(int *start, int *end);
void val_swap(int *x, int *y);

void quick_sort(int *A, int n) {
	quick_sort_helper(A, A+n-1);
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

