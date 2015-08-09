#pragma once

#define CMP_SWAP(i, j) if (a[i] > a[j])			\
	{ int tmp = a[i]; a[i] = a[j]; a[j] = tmp; }

void sort8_network(int *a)
{
    CMP_SWAP(0, 1); CMP_SWAP(2, 3); CMP_SWAP(4, 5); CMP_SWAP(6, 7);
    CMP_SWAP(0, 2); CMP_SWAP(1, 3); CMP_SWAP(4, 6); CMP_SWAP(5, 7);
    CMP_SWAP(1, 2); CMP_SWAP(5, 6); CMP_SWAP(0, 4); CMP_SWAP(1, 5);
    CMP_SWAP(2, 6); CMP_SWAP(3, 7); CMP_SWAP(2, 4); CMP_SWAP(3, 5);
    CMP_SWAP(1, 2); CMP_SWAP(3, 4); CMP_SWAP(5, 6);
}