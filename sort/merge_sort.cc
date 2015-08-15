#include <iostream>
#include <math.h>
#include <omp.h>

using namespace std;

inline void merge(int *C, int *A, int *B, int na, int nb) {
    while (na > 0 && nb > 0) {
    	if (*A <= *B) {
	    *C++ = *A++; na--;
	} else {
	    *C++ = *B++; nb--;
	}
    }
    while (na > 0) {
	*C++ = *A++; na--;
    }
    while (nb >0) {
	*C++ = *B++; nb--;
    }
}

inline void merge_sort_helper(int *B, int *A, int n) {
    if (n == 1) {
	B[0] = A[0];
	return;
    }
    int *C = new int[n];
    merge_sort_helper(C, A, n/2);
    merge_sort_helper(C + n/2, A + n/2, n - n/2);
    merge(B, C, C + n/2, n/2, n - n/2);
    delete [] C;
}

inline void merge_sort(int *A, int n) {
    int *B = new int[n];
    merge_sort_helper(B, A, n);
    for (int i = 0; i < n; ++i) {
	A[i] = B[i];
    }
    delete [] B;
}

// _end pointer point not to the last element, but one past and never access it.
template< class _Type >
inline void merge_ptr( const _Type* a_start, const _Type* a_end, const _Type* b_start, const _Type* b_end, _Type* dst )
{
    while( a_start < a_end && b_start < b_end ) {
        if ( *a_start <= *b_start )  *dst++ = *a_start++;    // if elements are equal, then a[] element is output
        else                        *dst++ = *b_start++;
    }
    while( a_start < a_end ) *dst++ = *a_start++;
    while( b_start < b_end ) *dst++ = *b_start++;
}

template< class _Type >
inline int my_binary_search( _Type value, const _Type* a, int left, int right )
{
    long low  = left;
    long high = fmax( left, right + 1 );
    while( low < high )
    {
        long mid = ( low + high ) / 2;
        if ( value <= a[ mid ] ) high = mid;
        else                        low  = mid + 1; // because we compared to a[mid] and the value was larger than a[mid].
                                                    // Thus, the next array element to the right from mid is the next possible
                                                    // candidate for low, and a[mid] can not possibly be that candidate.
    }
    return high;
}
template < class Item >
inline void exchange( Item& A, Item& B )
{
    Item t = A;
    A = B;
    B = t;
}

template< class _Type >
inline void merge_parallel_L5( _Type* t, int p1, int r1, int p2, int r2, _Type* a, int p3 )
{
    int length1 = r1 - p1 + 1;
    int length2 = r2 - p2 + 1;
    if ( length1 < length2 ) {
        exchange(      p1,      p2 );
        exchange(      r1,      r2 );
        exchange( length1, length2 );
    }
    if ( length1 == 0 ) return;
    if (( length1 + length2 ) <= 16392)
        merge_ptr( &t[ p1 ], &t[ p1 + length1 ], &t[ p2 ], &t[ p2 + length2 ], &a[ p3 ] );
    else {
        int q1 = ( p1 + r1 ) / 2;
        int q2 = my_binary_search( t[ q1 ], t, p2, r2 );
        int q3 = p3 + ( q1 - p1 ) + ( q2 - p2 );
        a[ q3 ] = t[ q1 ];
        //tbb::parallel_invoke(
        //Concurrency::parallel_invoke(
	//[&] { merge_parallel_L5( t, p1,     q1 - 1, p2, q2 - 1, a, p3     ); },
	//[&] { merge_parallel_L5( t, q1 + 1, r1,     q2, r2,     a, q3 + 1 ); }
        //);
	#pragma omp parallel
	{
	    merge_parallel_L5(t, p1, q1-1, p2, q2-1, a, p3);
	    merge_parallel_L5(t, q1+1, r1, q2, r2, a, q3+1);
	}
    }
}

/*int main(void) {
    int t[] = {0, 2, 4, 5, 3, 5, 7, 9};
    int res[] = {0, 0, 0, 0, 0, 0};
    merge_parallel_L5(t, 0, 3, 4, 7, res, 0);
    for (int i = 0; i < 8; i++) cout << res[i] << " ";
}
*/
