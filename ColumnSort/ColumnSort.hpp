#ifndef _COLUMN_SORT_
#define _COLUMN_SORT_

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

namespace ColumnSort {
  void Sort( int * In, int Row, int Col ) {
    using namespace std;

    int A[3][9];
    int rr = 0, cc = 0;
    for( int i = 0; i < 27; ++i ) {
      A[cc][rr] = In[i];
      rr++;
      if( rr >= 9 ) {
	rr = 0;
	cc++;
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < 3; ++i ) {
      sort( &A[i][0], &A[i][9] );
    }

    //
    // Transpose
    //
    int B[3][9];
    int row = 0, col = 0;
    for( int j = 0; j < 3; ++j ) {
      for( int i = 0; i < 9; ++i ) {
	B[row][col] = A[j][i];
	++row;
	if( row >= 3 ) {
	  row = 0;
	++col;
	}
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < 3; ++i ) {
      sort( &B[i][0], &B[i][9] );
    }

    //
    // Untranspose
    //
    row = 0; col = 0;
    for( int i = 0; i < 9; ++i ) {
      for( int j = 0; j < 3; ++j ) {
	A[row][col] = B[j][i];
	++col;
	if( col >= 9 ) {
	  col = 0;
	  ++row;
	}
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < 3; ++i ) {
      sort( &A[i][0], &A[i][9] );
    }

    int tmp[5];
    for( int i = 0; i < 5; ++i ) {
      tmp[i] = A[0][i];
    }


    row = 5;
    col = 0;
    for( int j = 0; j < 3; ++j ) {
      for( int i = 0; i < 9; ++i ) {
	B[j][i] = A[col][row];
	row++;
	if( row >= 9 ) {
	  row = 0;
	  col++;
	}
	if( col >= 3 ) {
	  break;
	}
      }
    }


    for( int i = 4; i < 9; ++i ) {
      B[2][i] = INT_MAX;
    }

    //
    // Sort columns
    //
    for( int i = 0; i < 3; ++i ) {
      sort( &B[i][0], &B[i][9] );
    }

    for( int i = 0; i < 5; ++i ) {
      A[0][i] = tmp[i];
    }

    row = 5;
    col = 0;
    for( int j = 0; j < 3; ++j ) {
      for( int i = 0; i < 9; ++i ) {
	A[col][row] = B[j][i];
	row++;
	if( row >= 9 ) {
	  row = 0;
	  col++; 
	}
	if( col >= 3 ) {
	  break;
	}
      }
    }


    for( int i = 0; i < 9; ++i ) {
      for( int j = 0; j < 3; ++j ) {
  	cout << A[j][i] << ", ";
      }
      cout << endl;
    }
  }
}

#endif
