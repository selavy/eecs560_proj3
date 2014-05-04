#include <iostream>
#include <cstdlib>
#include "InsertionSort.hpp"

using namespace std;

#define N 2000

struct Cmp {
  bool operator()( int a, int b) const { return a < b; }
};

int main( int argc, char ** argv ) {
  srand(1);
  int arr[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
    //    cout << arr[i] << " ";
  }
  //  cout << endl;

  cout << (InsertionSort::Sort( &arr[0], &arr[N] )).count() << endl;
  //
  // To sort in ascending order:
  // InsertionSort::Sort( &arr[0], &arr[N], GreaterThan() );
  //

  //for( int i = 0; i < N; ++i ) {
  //  cout << arr[i] << " ";
  //}
  //cout << endl;
  return 0;
}

