//bubble sort using pointer/call by reference
#include <stdio.h>
#define SIZE 10

void bubbleSort( int *const b , const int arraySize );

int main( void )
{
    int a[ SIZE ] = { 5 , 2 , 1 , 3 , 4 , 9 , 8 , 7 , 6 , 0 };
    bubbleSort( &a[ 0 ] , SIZE );

    for ( int j = 0; j < SIZE; ++j ){
        printf( "%2d" , a[ j ] );
    }

    return 0;
}

void bubbleSort( int *const b , const int arraySize )
{
    void swap( int *elementPtr1 , int *elementPtr2 );
    int i , pass;

    for ( pass = 1; pass < arraySize; ++pass ){
        for ( i = 0; i < arraySize - 1; ++i ){
            if ( b[ i ] > b[ i + 1 ] ){
                swap( &b[ i ] , &b[ i + 1 ] );
            }
        }//end i for
    }//end pass for
}

void swap( int *elementPtr1 , int *elementPtr2 )
{
    int hold;
    hold = *elementPtr1;
    *elementPtr1 = *elementPtr2;
    *elementPtr2 = hold;
}
