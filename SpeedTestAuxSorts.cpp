#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <chrono>
#include <ratio>
//#include "InsertionSort/InsertionSort.hpp"
#include "MergeSort/MergeSort.hpp"

#define RAND_NUM ( (rand() % (4*n)) - (2*n) )
#define NUM_TESTS 10

using namespace std;

int main( int argc, char ** argv ) {
  srand( 1 );
  vector<int> N = { 36000, 72000, 144000, 288000 };
  for( auto& n : N ) {
    int * data = new int[n];
    for( int i = 0; i < NUM_TESTS; ++i ) {
      cout << "n = " << n << ", ";
      generate( &data[0], &data[n], [&]() { return RAND_NUM; } );
      //      cout << InsertionSort::Sort( &data[0], &data[n] ).count() << endl;
      cout << MergeSort::Sort( data, 0, n ).count() << endl;
    }
    delete[] data;
  }
  
  return 0;
}
