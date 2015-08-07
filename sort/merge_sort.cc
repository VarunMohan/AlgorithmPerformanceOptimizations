inline void merge(int *C, int *A, int *B, int na, int nb) {
	while (na > 0 && nb > 0) {
    	if (*A <= *B) {
			*C++ = *A++; na--;
     	 } else {
			*C++ = *B++; nb--;
     	 }
    }
    while (na > 0) {
      *C++ = *A++; na--;
    }
    while (nb >0) {
      *C++ = *B++; nb--;
	}
}

inline void merge_sort_helper(int *B, int *A, int n) {
    if (n == 1) {
      B[0] = A[0];
      return;
    }
    int *C = new int[n];
    merge_sort_helper(C, A, n/2);
    merge_sort_helper(C + n/2, A + n/2, n - n/2);
    merge(B, C, C + n/2, n/2, n - n/2);

    delete [] C;
  }

inline void merge_sort(int *A, int n) {
	int *B = new int[n];
	merge_sort_helper(B, A, n);
	for (int i = 0; i < n; ++i) {
	    A[i] = B[i];
	}

	delete [] B;
}
