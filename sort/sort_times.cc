#include <iostream>
#include <algorithm>
#include <ctime>
#include <random>
#include <sys/time.h>
#include <map>
#include "limits.h"

#include "merge_sort.cc"
#include "merge_sort_optimized.cc"
#include "quick_sort.cc"
#include "heap_sort.cc"
#include "sedgesort.cc"

using namespace std;

int sizes[] = {100, 1000, 10000, 100000, 1000000};
int n_rep = 20;

void std_sort(int *arr, int n) {
    sort(arr, arr + n);
}

long int get_time() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (long int)(tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void check(int *arr, int *original, int n) {
    std_sort(original, n);
    for (int i = 0; i < n; i++) {
	if (original[i] != arr[i]) {
	    cout << "WRONG" << endl;
	    exit(0);
	}
    }
}

void generate_random_array(int *out, int n) {
    for (int i = 0; i < n; i++) out[i] = rand();
}

void std_stable_sort(int *arr, int n) {
        std::stable_sort(arr, arr+n);
}

int cmp (const void *a, const void *b) {
        return ( *(int*)a - *(int*)b);
}

void std_qsort(int *arr, int n) {
        qsort(arr, n, sizeof(int), cmp);
}

void benchmark(void (sort)(int *, int), char *name, bool check_sorted) {
    cout << "Sort Method: " << name << endl;
    for (int j = 0; j < sizeof(sizes)/sizeof(int); j++) {
        long int total_time = 0;
        int *arr = new int[sizes[j]];
	int *cp = new int[sizes[j]];
        for (int i = 0; i < n_rep; i++) {
            generate_random_array(arr, sizes[j]);
	    memcpy(cp, arr, sizeof(int)*sizes[j]);
            long int t1 = get_time();
            sort(arr, sizes[j]);
            t1 = get_time() - t1;
            if (check_sorted) {
                check(arr, cp, sizes[j]);
            }
            total_time += t1;
        }
        delete [] arr;
        double avg_time = (double)total_time / (double)n_rep;
        cout << "Size: " << sizes[j] << " with time: " << avg_time << " milliseconds" << endl;
    }
}

int main(void) {
    srand(time(NULL));
    //benchmark(merge_sort, (char *)"merge_sort", true);
    benchmark(merge_sort_optimized2, (char *)"merge_sort_optimized2", true);
    benchmark(merge_sort_optimized3, (char *)"merge_sort_optimized3", true);
    benchmark(merge_sort_optimized4, (char *)"merge_sort_optimized4", true);
    //benchmark(quick_sort, (char*) "quick_sort", true);
    //benchmark(quickSortVV, (char*) "quickSortVV", true);
    //benchmark(heap_sort, (char*) "heap_sort", true);
    //benchmark(std_stable_sort, (char *)"std_stable_sort", true);
    benchmark(std_sort, (char*)"std_sort", true);
    //benchmark(sedgesort, (char*)"sedgesort", true);
    //benchmark(std_qsort, (char*)"std_qsort", true);
}
