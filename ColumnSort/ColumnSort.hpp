#ifndef _COLUMN_SORT_
#define _COLUMN_SORT_

#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>

namespace ColumnSort {
  void Sort( int * In, int Col, int Row ) {
    using namespace std;

    const int TotalLen = Col * Row;
    int ShiftAmount = Row;
    if( ShiftAmount & 1 ) { // want ceiling, so if odd, then add one
      ShiftAmount++;
    }
    ShiftAmount /= 2;

    int A[Col][Row];
    int rr = 0, cc = 0;
    for( int i = 0; i < TotalLen; ++i ) {
      A[cc][rr] = In[i];
      rr++;
      if( rr >= Row ) {
	rr = 0;
	cc++;
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < Col; ++i ) {
      sort( &A[i][0], &A[i][Row] );
    }

    //
    // Transpose
    //
    int B[Col][Row];
    int row = 0, col = 0;
    for( int j = 0; j < Col; ++j ) {
      for( int i = 0; i < Row; ++i ) {
	B[row][col] = A[j][i];
	++row;
	if( row >= Col ) {
	  row = 0;
	++col;
	}
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < Col; ++i ) {
      sort( &B[i][0], &B[i][Row] );
    }

    //
    // Untranspose
    //
    row = 0; col = 0;
    for( int i = 0; i < Row; ++i ) {
      for( int j = 0; j < Col; ++j ) {
	A[row][col] = B[j][i];
	++col;
	if( col >= Row ) {
	  col = 0;
	  ++row;
	}
      }
    }

    //
    // Sort columns
    //
    for( int i = 0; i < Col; ++i ) {
      sort( &A[i][0], &A[i][Row] );
    }

    int tmp[ShiftAmount];
    for( int i = 0; i < ShiftAmount; ++i ) {
      tmp[i] = A[0][i];
    }


    row = ShiftAmount;
    col = 0;
    for( int j = 0; j < Col; ++j ) {
      for( int i = 0; i < Row; ++i ) {
	B[j][i] = A[col][row];
	row++;
	if( row >= Row ) {
	  row = 0;
	  col++;
	}
	if( col >= Col ) {
	  break;
	}
      }
    }


    const int FinalColumn = Col - 1;
    int FinalColumnShiftAmount = ShiftAmount;
    if( Row & 1 ) {
      --FinalColumnShiftAmount;
    }
    for( int i = FinalColumnShiftAmount; i < Row; ++i ) {
      B[FinalColumn][i] = INT_MAX;
    }

    //
    // Sort columns
    //
    for( int i = 0; i < Col; ++i ) {
      sort( &B[i][0], &B[i][Row] );
    }

    for( int i = 0; i < ShiftAmount; ++i ) {
      A[0][i] = tmp[i];
    }

    row = ShiftAmount;
    col = 0;
    for( int j = 0; j < Col; ++j ) {
      for( int i = 0; i < Row; ++i ) {
	A[col][row] = B[j][i];
	row++;
	if( row >= Row ) {
	  row = 0;
	  col++; 
	}
	if( col >= Col ) {
	  break;
	}
      }
    }


    for( int i = 0; i < Row; ++i ) {
      for( int j = 0; j < Col; ++j ) {
  	cout << A[j][i] << ", ";
      }
      cout << endl;
    }
  }
}

#endif
