#include <iostream>
#include <algorithm>
#include <set>
#include <stdlib.h>

const int target = 1E6;

int get_rand() {
	int x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) <<16;
	x |= (rand() & 0xff) << 24;
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

	for (int val : s) {
		*temp = val;
		temp++;
	}

	delete[] arr;
	std::cout << RAND_MAX <<std::endl;
	return 0;
}


