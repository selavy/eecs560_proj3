#include <iostream>
#include <cstdlib>
#include "MergeSort.hpp"

using namespace std;

#define N 30

struct Cmp {
  bool operator()( int a, int b) const { return a < b; }
};

int main( int argc, char ** argv ) {
  srand(1);
  int * arr = new int[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
    cout << arr[i] << " ";
  }
  cout << endl;

  //  MergeSort::Sort( &arr[0], &arr[N] );
  MergeSort::Sort( arr, 0, N );
  //
  // To sort in ascending order:
  // InsertionSort::Sort( &arr[0], &arr[N], GreaterThan() );
  //

  for( int i = 0; i < N; ++i ) {
    cout << arr[i] << " ";
  }
  cout << endl;

  delete[] arr;
  return 0;
}

