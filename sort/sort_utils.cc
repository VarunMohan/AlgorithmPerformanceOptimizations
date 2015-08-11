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

void sort4_network(int *a)
{
    CMP_SWAP(0, 1);
    CMP_SWAP(2, 3);
    CMP_SWAP(0, 2);
    CMP_SWAP(1, 3);
    CMP_SWAP(1, 2);
}

void sort2_network(int *a)
{
    CMP_SWAP(0, 1);
}

void small_sort(int *a, int n) {
    if (n == 1) return;
    else if (n <= 2) sort2_network(a);
    else if (n <= 4) sort4_network(a);
    else if (n <= 8) sort8_network(a);
}


void quickSortVV(int *arr, int elements) {

#define  MAX_LEVELS  1000

    int  piv, beg[MAX_LEVELS], end[MAX_LEVELS], i=0, L, R ;

    beg[0]=0; end[0]=elements;
    while (i>=0) {
	L=beg[i]; R=end[i]-1;
	if (L<R) {
	    piv=arr[L]; if (i==MAX_LEVELS-1) return;
	    while (L<R) {
		while (arr[R]>=piv && L<R) R--; if (L<R) arr[L++]=arr[R];
		while (arr[L]<=piv && L<R) L++; if (L<R) arr[R--]=arr[L]; }
	    arr[L]=piv; beg[i+1]=L+1; end[i+1]=end[i]; end[i++]=L; }
	else {
	    i--; }}
    return; }
