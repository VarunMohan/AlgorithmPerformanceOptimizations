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

inline void merge_sort_helper_optimized(int *B, int *A, int n) {
    if (n == 1) {
      B[0] = A[0];
      return;
    }
    int *C = new int[n];
    merge_sort_helper_optimized(C, A, n/2);
    merge_sort_helper_optimized(C + n/2, A + n/2, n - n/2);
    merge_optimized(B, C, C + n/2, n/2, n - n/2);
  }

inline void merge_sort_optimized(int *A, int n) {
	int *B = new int[n]; merge_sort_helper(B, A, n);
	for (int i = 0; i < n; ++i) {
		A[i] = B[i];
	}
}
