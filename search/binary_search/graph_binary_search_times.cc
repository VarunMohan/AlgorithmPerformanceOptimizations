#include <iostream>
#include <sys/time.h>
#include <random>

typedef void(*FunctionPointer)(int *, int, int);
int ARRAY_SZ[] = {10, 100, 1000, 5000, 10000, 50000, 100000, 1000000, 1000000000};
int N_REP = 100;
int RANGE = 1000000;

long int get_time() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (long int)(tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

int fill_array_with_elements(int *arr, int sz) {
    for (int i = 0; i < sz; i++)
	arr[i] = rand() % RANGE;
    return arr[rand() % sz];
}

void graph_binary_search(FunctionPointer *binary_search_methods, int n_methods) {
    int n_array_szes = sizeof(ARRAY_SZ) / sizeof(int);
    for (int j = 0; j < n_methods; j++) {
	FunctionPointer search = binary_search_methods[j];
	for (int i = 0; i < n_array_szes; i++) {
	    long int total_time = 0;
	    for (int k = 0; k < N_REP; k++) {
		int *arr = (int *)malloc(sizeof(int) * ARRAY_SZ[i]);
		int target = fill_array_with_elements(arr, ARRAY_SZ[i]);
		long int start_time = get_time();
		search(arr, target, ARRAY_SZ[i]);
		total_time += get_time() - start_time;
	    }
	    long int avg_time = total_time / N_REP;
	}
    }
}
