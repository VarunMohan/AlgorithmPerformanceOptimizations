#include <iostream>
#include <algorithm>
#include <set>
#include <stdlib.h>
#include "naive_search.cc"
#include <assert.h>

const int target = 1E6;

int get_rand() {
	int x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) <<16;
	return x;
}

int main() {
	srand (time(NULL));
	std::set<int> s;
	
	while (s.size() < target) {
		s.insert(get_rand());
	}
	
	int* arr = new int[target];
	int* temp = arr;

	for (std::set<int>::iterator it = s.begin(); it != s.end(); ++it) {
		std::cout << *it << std::endl;
		*temp = *it;
		temp++;
	}
	
	for (int i = 0; i < target; i++) {
		assert(search(arr, *(arr+i), target) == i);		
	}

	delete[] arr;
	
	std::cout << "SUCCESS" << std::endl;

	return 0;
}


