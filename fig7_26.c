#include <stdio.h>
#define SIZE 5

void bubble( int b[] , const int arraySize , int (*compare)( int x, int y ) );
int ascending( int x , int y );
int descending( int x , int y );
void swap( int *elementPtr1 , int *elementPtr2 );

int main( void )
{
    int count;
    int a[ 5 ] = { 1 , 3 , 5 , 2 , 4 };

    printf( "Data item in original order\n" );
    for ( count = 0; count < SIZE; ++count ){
        printf( "%2d" , a[ count ] );
    }printf( "\n" );

    bubble( a , SIZE , ascending );

    for ( count = 0; count < SIZE; ++count ){
        printf( "%2d" , a[ count ] );
    }printf( "\n" );

    return 0;
}

void bubble( int b[] , const int arraySize , int (*compare)( int x , int y ) )
{
    int i , pass;

    if ( compare == ascending ){
        printf( "Data item in ascending order %p == %p\n" , ascending , compare );
    }else if ( compare == descending ){
        printf( "Data item in descending order\n" );
    }

    for ( pass = 1; pass < arraySize; ++pass ){
        for ( i = 0; i < arraySize - 1; ++i ){
            if ( (*compare)( b[ i ] , b[ i + 1 ] ) ){
                swap( &b[ i ] , &b[ i + 1 ] );
            }
        }
    }
}

int ascending( int x , int y )
{
    return y < x;
}

int descending( int x , int y )
{
    return y > x;
}

void swap( int *elementPtr1 , int *elementPtr2 )
{
    int hold;
    hold = *elementPtr1;
    *elementPtr1 = *elementPtr2;
    *elementPtr2 = hold;
}
