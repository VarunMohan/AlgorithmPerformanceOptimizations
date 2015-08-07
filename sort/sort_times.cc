#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <sys/time.h>

#include "merge_sort.cc"
#include "merge_sort_optimized.cc"

using namespace std;

int sizes[] = {100, 1000, 10000, 100000, 1000000};
int n_rep = 20;

long int get_time() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (long int)(tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void check(int *arr, int n) {
    for (int i = 0; i < n-1; i++) {
	if (arr[i+1] < arr[i]) {
	    printf("WRONG!");
	    exit(0);
	}
    }
}

void generate_random_array(int *out, int n) {
    for (int i = 0; i < n; i++) out[i] = rand();
}

void std_sort(int *arr, int n) {
    sort(arr, arr + n);
}

void benchmark(void (sort)(int *, int), char *name, bool check_sorted) {
    cout << "Sort Method: " << name << endl;
    for (int j = 0; j < sizeof(sizes)/sizeof(int); j++) {
	long int total_time = 0;
	int *arr = new int[sizes[j] + 8];
	for (int i = sizes[j]; i < sizes[j] + 8; ++i) {
		arr[i] = INT_MAX;
	}
	for (int i = 0; i < n_rep; i++) {
	    generate_random_array(arr, sizes[j]);
	    long int t1 = get_time();
	    sort(arr, sizes[j]);
	    t1 = get_time() - t1;
	    if (check_sorted) {
		check(arr, sizes[j]);
	    }
	    total_time += t1;
	}
	delete arr;
	double avg_time = (double)total_time / (double)n_rep;
	cout << "Size: " << sizes[j] << " with time: " << avg_time << " milliseconds" << endl;
    }
}

int main(void) {
    srand(time(NULL));
    benchmark(merge_sort, (char *)"merge_sort", true);
    benchmark(merge_sort_optimized2, (char *)"merge_sort_optimized2", true);
    benchmark(merge_sort_optimized, (char *)"merge_sort_optimized", true);
    benchmark(merge_sort_optimized3, (char *)"merge_sort_optimized3", true);
    benchmark(merge_sort_optimized_pre_padded, (char *)"merge_sort_optimized_pre_padded", true);
    benchmark(std_sort, (char*)"std_sort", true);
}
