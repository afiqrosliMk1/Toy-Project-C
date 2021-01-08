#include <stdio.h>
#define SIZE 3

void modifyArray( int b[] , int arraySize );
void modifyElement( int c );

int main( void )
{
    int i;
    int a[ SIZE ] = { 0 , 1 , 2 };

    printf( "original array values:\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] );
    }printf( "\n" );

    modifyArray( a , SIZE );
    printf( "array values now:\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] );
    }printf( "\n" );

    modifyElement( a[ 0 ] );
    printf( "array element value now:\n" );
    printf( "%d\n" , a[ 0 ] );

    return 0;
}

void modifyArray( int b[] , int arraySize )
{
    int i;
    for ( i = 0; i < arraySize; ++i ){
        b[ i ] += 5;
    }printf( "array value before exiting modifyArray\n" );
    for ( i = 0; i < arraySize; ++i ){
        printf( "%d " , b[ i ] );
    }printf( "\n" );
}

void modifyElement( int c )
{
    c += 5;
    printf( "array element before exiting modifyElement\n" );
    printf( "%d\n" , c );
}
