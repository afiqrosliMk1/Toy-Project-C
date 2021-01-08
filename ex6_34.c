#include <stdio.h>
#include <stdbool.h>

#define N 8

bool solveNQUtil( int cBoard[][ N ] , int col );
bool solveNQ();
bool isSafe( const int cBoard[][ N ] , const int row , const int column );
void printBoard( int b[ N ][ N ] );

int main( void )
{
    solveNQ();

    return 0;
}

bool solveNQ()
{
    int board[ N ][ N ] = { 0 };

    if ( solveNQUtil( board , 0 ) == false ){
        printf( "Solution does not exist\n" );
        return false;
    }

    printBoard( board );
    return true;
}

bool solveNQUtil( int cBoard[][ N ] , int col )
{
    int i;

    if ( col >= N ){
        return true;
    }
    for ( i = 0; i < N; ++i ){
        if ( isSafe( cBoard , i , col ) ){
            cBoard[ i ][ col ] = 1;
            if ( solveNQUtil( cBoard , col + 1 ) ){
                return true;
            }
            cBoard[ i ][ col ] = 0;
        }
    }
    return false;
}


bool isSafe( const int cBoard[][ N ] , const int row , const int column )
{
    int i , j;
    //check to column to the left
    for ( i = row , j = column; j >= 0; --j  ){
        if ( cBoard[ i ][ j ] != 0 )
            return false;
    }

    //check upper left diagonal
    for ( i = row , j = column ; i >= 0 && j >= 0; --i , --j ){
        if ( cBoard[ i ][ j ] != 0 )
            return false;
    }

    for ( i = row , j = column; i < N && j >= 0; ++i , --j ){
        if ( cBoard[ i ][ j ] != 0 )
            return false;
    }
    return true;
}

void printBoard( int b[ N ][ N ] )
{
    int i , j;

    for ( i = 0; i < N; ++i ){
        for ( j = 0; j < N; ++j ){
            printf( "%2d" , b[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}
