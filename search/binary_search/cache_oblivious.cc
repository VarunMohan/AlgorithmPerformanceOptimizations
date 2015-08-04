inline int binary_search_low_high(int *arr, int target, int n_elements, int low, int high) {
    while (low <= high) {
	int mid = (low + high) / 2;
	if (arr[mid] == target) return mid;
	bool x = arr[mid] < target;
	low = mid + x;
	high = mid + x-1;
    }
    return -1;
}

int cache_oblivious(int *arr, int target, int n_elements) {
    if (*arr == target) return 0;
    int start = 1;
    while (arr[start] < target) {
	start*=2;	
	if (start > n_elements) return binary_search_low_high(arr, target, n_elements, start/2, n_elements-1);
    }
    return binary_search_low_high(arr, target, n_elements, start/2, start);
}
