#ifndef _COLUMN_SORT_
#define _COLUMN_SORT_

//#define DEBUG

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <climits>
#include <cassert>
#include <chrono>
#include <chrono>
#include <utility>

namespace ColumnSort {
  //  template<long Col>
  std::chrono::duration<double> Sort( int * In, long Col, long N ) {
    using namespace std;
    using namespace std::chrono;
    assert( Col > 0 );
    //
    // Check that N is divisible by Col
    //
    assert( (N % Col) == 0 );

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    const long Row = N / Col;
    const long TotalLen = Col * Row;
    long ShiftAmount = Row - (Row / 2);
    //if( ShiftAmount & 1 ) { // want ceiling, so if odd, then add one
    //  ShiftAmount++;
    //}
    //ShiftAmount /= 2;

    //    int A[Col][Row];
    int ** A = new int*[Col];
    for( long i = 0; i < Col; ++i ) {
      A[i] = new int[Row];
    }

    long rr = 0, cc = 0;
    for( long i = 0; i < TotalLen; ++i ) {
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
    for( long i = 0; i < Col; ++i ) {
      sort( &A[i][0], &A[i][Row] );
    }
    
#ifdef DEBUG
    cout << "1. After first sort column" << endl;
    // PRINT
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << A[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    //
    // Transpose
    //
    //    int B[Col][Row];
    int ** B = new int*[Col];
    for( long i = 0; i < Col; ++i ) {
      B[i] = new int[Row];
    }

    long row = 0, col = 0;
    for( long j = 0; j < Col; ++j ) {
      for( long i = 0; i < Row; ++i ) {
	B[row][col] = A[j][i];
	++row;
	if( row >= Col ) {
	  row = 0;
	++col;
	}
      }
    }

#ifdef DEBUG
    // PRINT
    cout << "2. After Transpose" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << B[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    //
    // Sort columns
    //
    for( long i = 0; i < Col; ++i ) {
      sort( &B[i][0], &B[i][Row] );
    }

#ifdef DEBUG
    // PRINT
    cout << "3. After sort" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( lond j = 0; j < Col; ++j ) {
  	cout << setw(4) << B[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    //
    // Untranspose
    //
    row = 0; col = 0;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
	A[row][col] = B[j][i];
	++col;
	if( col >= Row ) {
	  col = 0;
	  ++row;
	}
      }
    }

#ifdef DEBUG   
    // PRINT
    cout << "4. After untranspose" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << A[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    //
    // Sort columns
    //
    for( long i = 0; i < Col; ++i ) {
      sort( &A[i][0], &A[i][Row] );
    }

#ifdef DEBUG
    // PRINT
    cout << "5. After sort" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << A[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    int tmp[ShiftAmount];
    for( long i = 0; i < ShiftAmount; ++i ) {
      tmp[i] = A[0][i];
    }

    sort( &tmp[0], &tmp[ShiftAmount] );

    row = ShiftAmount;
    col = 0;
    for( long j = 0; j < Col; ++j ) {
      for( long i = 0; i < Row; ++i ) {
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

    const long FinalColumn = Col - 1;
    long FinalColumnShiftAmount = Row / 2;
    //    if( Row & 1 ) {
    // ++FinalColumnShiftAmount;
    //}
    for( long i = FinalColumnShiftAmount; i < Row; ++i ) {
      B[FinalColumn][i] = INT_MAX;
    }

#ifdef DEBUG
    // PRINT
    cout << "6. After shift" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << B[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    //
    // Sort columns
    //
    for( long i = 0; i < Col; ++i ) {
      sort( &B[i][0], &B[i][Row] );
    }

#ifdef DEBUG
    // PRINT
    cout << "7. After sort" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << B[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
    // END PRINT
#endif

    for( long i = 0; i < ShiftAmount; ++i ) {
      A[0][i] = tmp[i];
    }

    row = ShiftAmount;
    col = 0;
    for( long j = 0; j < Col; ++j ) {
      for( long i = 0; i < Row; ++i ) {
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

    // Uncomment to print the arrays
#ifdef DEBUG
    cout << "8. After unshift" << endl;
    for( long i = 0; i < Row; ++i ) {
      for( long j = 0; j < Col; ++j ) {
  	cout << setw(4) << A[j][i] << ", ";
      }
      cout << endl;
    }
    cout << endl; 
#endif
    //

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double> >( t2 - t1 );


    for( long j = 0, t = 0; j < Col; ++j ) {
      for( long i = 0; i < Row; ++t, ++i ) {
	In[t] = A[j][i];
      }
    }

    for( long i = 0; i < Col; ++i ) {
      delete[] A[i];
      delete[] B[i];
    }

    delete[] A;
    delete[] B;

    return std::move( time_span );

  } //:~)) end Sort()

}

#endif
