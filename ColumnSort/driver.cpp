#include <iostream>
#include <cstdlib>
#include <vector>
#include "ColumnSort.hpp"

using namespace std;

#define RR

#ifdef RR
#define N 1000000
#else
#define N 27
#endif

int main( int argc, char ** argv ) {
#ifdef RR
  srand(1);
  int * arr = new int[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
  }
  vector<int> vec( N );
  copy( &arr[0], &arr[N], vec.begin() );
  sort( vec.begin(), vec.end() );
#else
  int arr[] = { 14, 3, 21, 24, 8, 26, 19, 10, 2, 25, 1, 12, 23, 13, 4, 17, 15, 20, 9, 27, 7, 16, 18, 5, 22, 11, 6  };
#endif

  ColumnSort::Sort<10>( arr, N );

#ifdef RR
    for( int i = 0; i < N; ++i ) {
   if( vec[i] != arr[i] ) {
     cerr << "ERROR: " << arr[i] << " != " << vec[i] << endl;
   }
  }
#else
  for_each( &arr[0], &arr[N], [](int i) { cout << i << " "; } );
  cout << endl;
#endif

  delete[] arr;
  return 0;
}

