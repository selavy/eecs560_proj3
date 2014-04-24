#include <iostream>
#include <cstdlib>
#include "InsertionSort.hpp"

using namespace std;

#define N 30

struct cmp {
  bool operator()() { return true; }
};

int main( int argc, char ** argv ) {
  srand(1);
  int arr[N];
  
  for( int i = 0; i < N; ++i ) {
    arr[i] = rand() % (10*N);
    cout << arr[i] << " ";
  }
  cout << endl;

  InsertionSort::Sort( &arr[0], &arr[N] );

  for( int i = 0; i < N; ++i ) {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}

