int binary_search(int *arr, int target, int n_elements) {
    int low=0, high=n_elements-1;
    while (low <= high) {
	int mid = (low + high) / 2;
	if (arr[mid] == target) return mid;
	if (arr[mid] < target) low = mid+1;
	else high = mid-1;
    }
    return -1;
}
