#include <iostream>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include "linear_search.cc"
#include <time.h>
#include <assert.h>

const int num_terms = 1E5;

int get_rand() {
	int x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) <<16;
	return x;
}

int main() {
	srand (time(NULL));
	std::set<int> s;
	
	while (s.size() < num_terms) {
		s.insert(get_rand());
	}
	
	int* arr = new int[num_terms];
	int* temp = arr;

	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		*temp = *it;
		temp++;
	}
	
	int start = time(NULL);

	for (int i = 0; i < num_terms; i++) {
		assert(search(arr, *(arr+i), num_terms) == i);		
	}

	std::cout << "TIME PER ACCESS: " << 1.0 * (time(NULL) - start)/num_terms * 1E6 << "mus" << std::endl;

	delete[] arr;
	
	return 0;
}


