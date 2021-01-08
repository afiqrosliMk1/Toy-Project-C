#include <stdio.h>
#include <stdbool.h>
#define N 8

bool solveNQUtil( int board[][ N ] , int col );
bool isSafe( int b[][ N ] , int row , int column );
void printBoard( int b[][ N ] );

int main( void )
{
    int board[ N ][ N ] = { 0 };

    if ( solveNQUtil( board , 0 ) == false ){
        printf( "Solution not exist\n" );
    }
    printBoard( board );

    return 0;
}

bool solveNQUtil( int board[][ N ] , int col )
{
    int i;

    if ( col >= N )
        return true;
    for ( i = 0; i < N; ++i ){
        if ( isSafe( board , i , col ) ){
            board[ i ][ col ] = 1;
            if ( solveNQUtil( board , col + 1 ) )
                return true;
            board[ i ][ col ] = 0;
        }
    }
    return false;
}

bool isSafe( int b[][ N ] , int row , int column )
{
    int i , j;
    //try every left column
    for ( i = row , j = column; j >= 0; --j ){
        if ( b[ i ][ j ] != 0 )
            return false;
    }

    //try for upper left diagonal
    for ( i = row , j = column; i >= 0 && j >= 0; --i , --j ){
        if ( b[ i ][ j ] != 0 )
            return false;
    }

    //try for lower left diagonal
    for ( i = row , j = column; i < N && j >= 0; ++i , --j ){
        if ( b[ i ][ j ] != 0 )
            return false;
    }

    return true;
}


void printBoard( int b[][ N ] )
{
    int j , k;

    for ( j = 0; j < N; ++j ){
        for ( k = 0; k < N; ++k  ){
            printf( "%2d" , b[ j ][ k ] );
        }printf( "\n" );
    }printf( "\n" );
}
