#include <iostream>
#include <cstdlib>
#include "ColumnSort.hpp"

using namespace std;

#define N 90

struct Cmp {
  bool operator()( int a, int b) const { return a < b; }
};

int main( int argc, char ** argv ) {
  srand(1);
  int arr[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
    cout << arr[i] << " ";
  }
  cout << endl;

  ColumnSort::Sort( arr, 3, N / 3 );

  return 0;
}

