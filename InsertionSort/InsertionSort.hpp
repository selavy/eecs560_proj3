#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

#include <iostream>

namespace InsertionSort {
  struct LessThan {
    bool operator()( int a, int b ) const { return( a < b ); }
  };

  struct GreaterThan {
    bool operator()( int a, int b ) const { return( a > b ); }
  };

  template<typename T, typename Compare = LessThan>
  void Sort( T* begin, T* end, Compare Comp = LessThan() ) {
    T* j;
    for( T* p = begin; p < end; ++p ) {
      T tmp = *p;
      //  for( j = p; ( j > (begin - 1) ) && ( tmp < *(j-1) ); --j ) {
      for( j = p; ( j > ( begin - 1 ) ) && Comp( tmp, *(j - 1) ); --j ) {
	*j = *(j-1);
      }
      *j = tmp;
    }
  }
  
}

#endif
