#include "sort_utils.cc"

void sort_le_8(int *out, int *in, int n) {
    int aux[8];
    for (int i = 0; i < n; i++) aux[i] = in[i];
    for (int i = n; i < 8; i++) aux[i] = INT_MAX;
    sort8_network(aux);
    for (int i = 0; i < n; i++) out[i] = aux[i];
}

inline void merge_optimized(int *C, int *A, int *B, int na, int nb) {
	while (na > 0 && nb > 0) {
    	int cmp = (*A <= *B);
    	int min = *B ^ ((*A ^ *B) & (~cmp));
    	*C++ = min;
    	A += cmp;
    	B += 1-cmp;
    	na -= cmp;
    	nb -= 1-cmp;
    }
    while (na > 0) {
      *C++ = *A++; na--;
    }
    while (nb >0) {
      *C++ = *B++; nb--;
	}
}

inline void merge_sort_helper_optimized2(int *aux, int *B, int *A, int n) {
    if (n == 1) {
	B[0] = A[0];
	return;
    }
    merge_sort_helper_optimized2(aux + n, aux, A, n/2);
    merge_sort_helper_optimized2(aux + n, aux + n/2, A + n/2, n - n/2);
    merge(B, aux, aux + n/2, n/2, n-n/2);
}

inline void merge_sort_helper_optimized(int *aux, int *sorted, int *start, int *end) {
    int n = (end-start);
    if (n == 1) {
	sorted[0] = *start;
	return;
    }

    int *mid = start + n/2;
    merge_sort_helper_optimized(aux, aux, start, mid);
    merge_sort_helper_optimized(aux + n/2, aux + n/2, mid, end);
    merge(sorted, aux, aux + n/2, mid - start, end - mid);
  }

inline void merge_sort_helper_optimized3(int *aux, int *sorted, int *start, int *end) {
    int n = (end-start);
    if (n == 1) {
	sorted[0] = *start;
	return;
    }
    if (n <= 8) {
	sort8_network(aux);
	return;
    }

    int *mid = start + n/2;
    merge_sort_helper_optimized3(aux, aux, start, mid);
    merge_sort_helper_optimized3(aux + n/2, aux + n/2, mid, end);
    merge(sorted, aux, aux + n/2, mid - start, end - mid);
  }

inline void merge_sort_optimized2(int *A, int n) {
	int *B = new int[n];
	int *aux = new int[2*n+1];
	merge_sort_helper_optimized2(aux, B, A, n);
	for (int i = 0; i < n; ++i) {
		A[i] = B[i];
	}

	delete [] B;
	delete [] aux;
}

inline void merge_sort_optimized(int *A, int n) {
        int *B = new int[n];
	merge_sort_helper_optimized(A, B, A, A+n);
	for (int i = 0; i < n; ++i) {
	    A[i] = B[i];
	}

	delete [] B;
}

inline void merge_sort_optimized3(int *A, int n) {
	int *B = new int[n+8];
	int *C = new int[n+8];

	for (int i = n; i < n + 8; ++i) {
		B[i] = INT_MAX;
		C[i] = INT_MAX;
	}

	for (int i = 0; i < n; ++i) {
		C[i] = A[i];
	}

	merge_sort_helper_optimized3(C, B, C, C+n);
	for (int i = 0; i < n; ++i) {
		A[i] = B[i];
	}

	delete [] B;
	delete [] C;
}
