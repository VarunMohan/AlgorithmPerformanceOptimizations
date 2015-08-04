int linear_search(int *arr, int target, int n_elements) {
	for (int i = 0; i < n_elements; i++) {
		if (*(arr + i) == target) return i;
	}
	return -1;
}
