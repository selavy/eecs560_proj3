#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

#include <iostream>
#include <chrono>
#include <ratio>
#include <utility>

namespace InsertionSort {
  struct LessThan {
    bool operator()( int a, int b ) const { return( a < b ); }
  };

  struct GreaterThan {
    bool operator()( int a, int b ) const { return( a > b ); }
  };

  template<typename T, typename Compare = LessThan>
  std::chrono::duration<double> Sort( T* begin, T* end, Compare Comp = LessThan() ) {
    using namespace std::chrono;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    T* j;
    for( T* p = begin; p < end; ++p ) {
      T tmp = *p;
      for( j = p; ( j > ( begin + 1 ) ) && Comp( tmp, *(j - 1) ); --j ) {
	*j = *(j-1);
      }
      *j = tmp;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >( t2 - t1 );
    return std::move( time_span );
  }
  
}

#endif
