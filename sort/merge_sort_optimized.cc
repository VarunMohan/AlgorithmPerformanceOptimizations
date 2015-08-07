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


inline void merge_sort_optimized2(int *A, int n) {
	int *B = new int[n];
	int *aux = new int[2*n+1];
	merge_sort_helper_optimized2(aux, B, A, n);
	for (int i = 0; i < n; ++i) {
		A[i] = B[i];
	}

	delete B;
	delete aux;
}

inline void merge_sort_optimized(int *A, int n) {
	int *B = new int[n];
	merge_sort_helper_optimized(A, B, A, A+n);
	for (int i = 0; i < n; ++i) {
		A[i] = B[i];
	}

	delete B;
}
