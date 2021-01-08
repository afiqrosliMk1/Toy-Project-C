#include <stdio.h>
#include <stdlib.h>

int duplicateTest( int n , const int store[ 20 ] );
void printArray( int a[ 20 ] );

int main( void )
{
    int num;
    int storeNumber[ 20 ] = { 0 };
    int moveCount = 0;

    while ( moveCount < 20 ){
        num = rand() % 20 + 1;
        if ( duplicateTest( num , storeNumber ) ){
            storeNumber[ moveCount ] = num;
            ++moveCount;
        }
    }

    printArray( storeNumber );

    return 0;
}

int duplicateTest( int n , const int store[ 20 ] )
{
    //return 1 if number is not duplicate
    //return 0 if number is duplicate
    int i;

    for ( i = 0; i < 20; ++i ){
        if ( store[ i ] == n ){
            return 0;
        }
    }return 1;
}

void printArray( int a[ 20 ] )
{
    int j;
    for ( j = 0; j < 20; ++j ){
        printf( "%3d" , a[ j ] );
    }printf( "\n" );
}
