class merge_sort {
public:
  static void MergeSort(int *B, int *A, int n) {
    if (n == 1) {
      B[0] = A[0];
      return;
    }
    double *C = new double[n];
    MergeSort(C, A, n/2);
    MergeSort(C + n/2, A + n/2, n - n/2);
    Merge(B, C, C + n/2, n/2, n - n/2);
  }

  static void Merge(int *C, int *A, int *B, int na, int nb) {
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
};
