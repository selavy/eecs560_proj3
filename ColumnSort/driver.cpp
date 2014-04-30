#include <iostream>
#include <cstdlib>
#include "ColumnSort.hpp"

using namespace std;

#define N 30

struct Cmp {
  bool operator()( int a, int b) const { return a < b; }
};

int main( int argc, char ** argv ) {
  /*
  srand(1);
  int arr[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
    cout << arr[i] << " ";
  }
  cout << endl;
  */

  int arr[27] = { 14, 3, 21, 24, 8, 26, 19, 10, 2,
		  25, 1, 12, 23, 13, 4, 17, 15, 20,
		  9, 27, 7, 16, 18, 5, 22, 11, 6 };

  ColumnSort::Sort( arr, 3, 9 );

  return 0;
}

