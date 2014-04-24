#ifndef _INSERTION_SORT_
#define _INSERTION_SORT_

#include <iostream>

namespace InsertionSort {
  int * j;

  void Sort( int* begin, int* end ) {
    for( int* p = begin; p < end; ++p ) {
      int tmp = *p;
      for( j = p; ( j > (begin - 1) ) && ( tmp < *(j-1) ); --j ) {
	*j = *(j-1);
      }
      *j = tmp;
    }
  }
  
}

#endif
