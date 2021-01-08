//modify program fig6_16 / mode can handle a tie
#include <stdio.h>
#define SIZE 8
void mean( int b[] , int arraySize );
void median( int b[] , int arraySize );
void mode( int freqSize , int b[] , int arraySize );
void bubbleSort( int c[] , int arraySize );

int main( void )
{
    int i;
    int range = 10; // the range of value in array is 1 - 9
    int a[ SIZE ] = { 3 , 1 , 9 , 9 , 1 , 4 , 9 , 1 };

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

    if ( arraySize % 2 != 0 ){ //odd
        for ( i = 0;  i < arraySize; ++i ){
            printf( "%d " , b[ i ] );
        }printf( "\n" );
        printf( "median = %d\n" , b[ arraySize / 2 ] );
    }else if ( arraySize % 2 == 0 ){ //even
        for ( i = 0;  i < arraySize; ++i ){
            printf( "%d " , b[ i ] );
        }printf( "\n" );
        printf( "median = %f\n" , (float)(b[ (arraySize - 1) / 2 ] + b[ (arraySize - 1) / 2 + 1 ]) / 2 );
    }

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

    for ( i = 0; i < freqSize; ++i ){ //initialize all frequency to zero
        frequency[ i ] = 0;
    }

    for ( i = 0; i < arraySize; ++i ){ //eg: if b[i] = 2 , frequency[ 2 ] = frequency[ 2 ] + 1;
        ++frequency[ b[ i ] ];
    }

    largest = frequency[ 0 ];
    for ( i = 1; i < freqSize; ++i ){
        if ( frequency[ i ] > largest ){
            largest = frequency[ i ];
            modeValue = i; //THIS IS VERY IMPORTANT
        }
    }//printf( "mode: %d\n" , modeValue );

    //this loop will trace which subscript in frequency array correspond to largest value
    printf( "mode: %d" , modeValue );
    for ( i = 1; i < freqSize; ++i ){
        if ( frequency[ i ] == largest && i != modeValue ){
            printf( " and %d" , i );
        }
    }printf( "\n" );
}
