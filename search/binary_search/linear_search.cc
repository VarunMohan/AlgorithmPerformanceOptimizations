#include <iostream>

#pragma once

#define unlikely(x)     __builtin_expect((x),0)

inline int linear_search(int *arr, int target, int n_elements) {
	for (int i = 0; i < n_elements; i++) {
	    if (*(arr + i) == target) return i;
	}
	return -1;
}

inline int linear_search_branch(int *arr, int target, int n_elements) {
	for (int i = 0; i < n_elements; i++) {
	    if (unlikely(*(arr + i) == target)) return i;
	}
	return -1;
}
