#include <stdio.h>
#define SIZE 9
void mean( int b[] , int arraySize );
void median( int b[] , int arraySize );
void mode( int freqSize , int b[] , int arraySize );
void bubbleSort( int c[] , int arraySize );

int main( void )
{
    int i;
    int range = 10; // the range of value in array is 1 - 9
    int a[ SIZE ] = { 1 , 1 , 4 , 9 , 2 , 5 , 1 , 3 , 7 };

    printf( "Initial array: " );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] );
    }printf( "\n" );

    median( a , SIZE );
    mode ( range , a , SIZE );
    mean( a , SIZE );
    return 0;
}

void mean( int b[] , int arraySize )
{
    int total = 0 , i;
    for ( i = 0; i < arraySize; ++i ){
        total += b[ i ];
    }
    printf( "mean = %f\n" , (float)total / arraySize );
}

void median( int b[] , int arraySize )
{
    int i;
    bubbleSort( b , arraySize );
    printf( "Array after bubbleSort: " );

    for ( i = 0;  i < arraySize; ++i ){
        printf( "%d " , b[ i ] );
    }printf( "\n" );
    printf( "median = %d\n" , b[ arraySize / 2 ] );
}

void bubbleSort( int c[] , int arraySize )
{
    int i , hold , pass;

    for ( pass = 1; pass < arraySize; ++pass ){
        for ( i = 0; i < arraySize - 1; ++i ){
            if ( c[ i ] > c[ i + 1 ] ){
                hold = c[ i ];
                c[ i ] = c[ i + 1 ];
                c[ i + 1 ] = hold;
            }
        }// i for
    }// pass for

}

void mode( int freqSize , int b[] , int arraySize )
{
    int frequency[ freqSize ];
    int largest = 0 , modeValue , i;

    for ( i = 0; i < freqSize; ++i ){
        frequency[ i ] = 0;
    }

    for ( i = 0; i < arraySize; ++i ){
        ++frequency[ b[ i ] ];
    }

    largest = frequency[ 0 ];
    for ( i = 0; i < freqSize; ++i ){
        if ( frequency[ i ] > largest ){
            largest = frequency[ i ];
            modeValue = i; //THIS IS VERY IMPORTANT
        }
    }printf( "mode: %d\n" , modeValue );
}
