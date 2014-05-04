#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "ColumnSort/ColumnSort.hpp"

using namespace std;

#define NUM_TESTS 10
#define RAND_NUM ((rand() % (4*n)) - (2*n))

int main( int argc, char ** argv ) {
  srand( 1 );
  vector<int> S = { 2, 3, 5, 10 };
  vector<int> N = { 36000, 72000, 144000, 288000, 1000000 };

  for( auto& n : N ) {
    int * data = new int[n];
    for( auto& s : S ) {
      if( s == 3 && n == 1000000 ) {
	continue;
      }
      for( int i = 0; i < NUM_TESTS; ++i ) {
	generate( &data[0], &data[n], [&]() { return RAND_NUM; }  );
	cout << "n = " << n << ", s = " << s << ", ";
	cout << ColumnSort::Sort( data, s, n ).count() << endl;
      }
    }
    delete[] data;
  }
  return 0;
}
