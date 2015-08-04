#include <iostream>
#include <sys/time.h>
#include <random>
#include <vector>
#include <fstream>
#include <assert.h>
#include "linear_search.cc"
#include "binary_search.cc"
#include "cache_oblivious.cc"
#include "binary_search_linear.cc"

typedef int(*FunctionPointer)(int *, int, int);
int ARRAY_SZ[] = {5000, 10000, 50000, 100000, 500000, 1000000, 2000000};
int N_REP = 100;
int RANGE = 1000000;

long int get_time() {
    struct timeval tp;
    gettimeofday(&tp, NULL);
    return (long int)(tp.tv_sec * 1000 + tp.tv_usec / 1000);
}

void fill_array_with_elements(int *arr, int sz) {
    for (int i = 0; i < sz; i++)
	arr[i] = i;
}

void graph_binary_search(FunctionPointer *binary_search_methods, char *names[], int n_methods) {
    int n_array_szes = sizeof(ARRAY_SZ) / sizeof(int);
    std::vector<std::vector<double> > xs, ys;
    for (int j = 0; j < n_methods; j++) {
	FunctionPointer search = binary_search_methods[j];
	std::vector<double> x_values, y_values;
	for (int i = 0; i < n_array_szes; i++) {
	    int *arr = new int[ARRAY_SZ[i]];
	    fill_array_with_elements(arr, ARRAY_SZ[i]);
	    long int start_time = get_time();
	    for (int k = 0; k < ARRAY_SZ[i]; k++) {
		assert(k == search(arr, *(arr+k), ARRAY_SZ[i]));
	    }
	    long int total_time = get_time() - start_time;
	    double avg_time = (double)total_time / ARRAY_SZ[i];
	    x_values.push_back(ARRAY_SZ[i]);
	    y_values.push_back(avg_time);
	    delete arr;
	}
	xs.push_back(x_values);
	ys.push_back(y_values);
    }
    for (int i = 0; i < n_methods; i++) {
	std::ofstream out(((std::string)names[i] + ".dat"));
	std::vector<double> x = xs[i], y = ys[i];
	for (int i = 0; i < x.size(); i++) {
	    out << x[i] << " " << y[i] << std::endl;
	}
	out.close();
    }
}

int main(void) {
    FunctionPointer search_methods[] = {binary_search, cache_oblivious};
    char *names[] = {(char *)"binary", (char*)"binary_search_linear"};
    graph_binary_search(search_methods, names, 2);
}
