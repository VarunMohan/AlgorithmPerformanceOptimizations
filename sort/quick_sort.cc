#include <algorithm>


void quick_sort(int *A, int n);
void quick_sort_helper(int *start, int *end);
int partition(int *start, int *end);

void quick_sort(int *A, int n) {
	quick_sort_helper(A, A+n-1);
}

void quick_sort_helper(int *start, int *end) {
	if (end - start > 0) {
		p = partition(start, end);
		quick_sort_helper(start, start + p - 1);
		quick_sort_helper(start + p + 1, hi);
	}
}

int partition(int *start, int *end) {
	int piv = *(end);
	int val = 0;
	for (int* j = start; j < end; j++) {
		if (*j <= piv) {
			val = val + 1;
			std::swap((start+val), j);
		}
	}
	std::swap((start+val), end);
	return val;
}

