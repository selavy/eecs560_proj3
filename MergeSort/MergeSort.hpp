#ifndef _MERGE_SORT_
#include <iostream>
#include <stack>
#include <algorithm>
#include <chrono>
#include <ratio>
#include <utility>

namespace MergeSort {
  void Merge( int *& A, int *& TmpArray, int leftPos, int rightPos, int rightEnd );

  std::chrono::duration<double> Sort( int *& A, int left, int right ) {
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    int m = 1;
    int * tmp = new int[right - left];
    while( m < right ) {
      int i = 0;
      while( i < (right - m) ) {
	//merge subarrays a[i..i+m-1] and a[i+m .. min(i+2*m-1,n-1)]
	const int rightLimit = std::min( i+2*m-1, right-1 );
	const int leftLimit = i;
	const int middleLimit = i+m;
	Merge( A, tmp, leftLimit, middleLimit, rightLimit );
	i = i + 2 * m;
      }
      m = m * 2;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >( t2 - t1 );
    delete[] tmp;
    return std::move( time_span );
  }

  void Merge( int *& A, int *& TmpArray, int leftPos, int rightPos, int rightEnd ) {
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    while( leftPos <= leftEnd && rightPos <= rightEnd ) {
      if( A[ leftPos ] <= A[ rightPos ] ) {
	TmpArray[tmpPos++] = A[leftPos++];
      } else {
	TmpArray[tmpPos++] = A[rightPos++];
      }
    }

    while( leftPos <= leftEnd ) {
      TmpArray[ tmpPos++ ] = A[ leftPos++ ];
    }
    
    while( rightPos <= rightEnd ) {
      TmpArray[ tmpPos++ ] = A[ rightPos++ ];
    }

    for( int i = 0; i < numElements; ++i, --rightEnd ) {
      A[ rightEnd ] = TmpArray[ rightEnd ];
    }
  }
}
#endif
