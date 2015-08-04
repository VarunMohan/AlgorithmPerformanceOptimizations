#include "linear_search.cc"

int binary_search_linear(int *arr, int target, int n_elements) {
    int low=0, high=n_elements-1;
    while (low <= high) {
    if (high - low <= 16) {
		return low + linear_search(arr + low, target, high-low + 1);
	}
	int mid = (low + high) / 2;
	if (arr[mid] == target) return mid;
	if (arr[mid] < target) low = mid+1;
	else high = mid-1;
    }
    return -1;
}
