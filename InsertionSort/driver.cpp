#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "InsertionSort.hpp"

using namespace std;

#define N 2000

struct Cmp {
  bool operator()( int a, int b) const { return a < b; }
};

int main( int argc, char ** argv ) {
  srand(1);
  int arr[N];
  vector<int> data( N );
  
  for( int i = 0; i < N; ++i ) {
    const int r = rand()  % (10*N);
    arr[i] = r;
    data[i] = r;
    //    cout << arr[i] << " ";
  }
  //  cout << endl;

  cout << (InsertionSort::Sort( &arr[0], &arr[N] )).count() << endl;
  //
  // To sort in ascending order:
  // InsertionSort::Sort( &arr[0], &arr[N], GreaterThan() );
  //
  
  sort( data.begin(), data.end() );

  for( int i = 0; i < N; ++i ) {
    //cout << arr[i] << " ";
    if( data[i] != arr[i] ) {
     cout << "Error " << data[i] << " != " << arr[i] << endl;
    }
  }
  //cout << endl;
  return 0;
}

