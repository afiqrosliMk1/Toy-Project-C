//modify bubble sort to function more efficiently
#include <stdio.h>
#define SIZE 5

void bubbleSort( int b[] );
void printArray( int b[] );

int main( void )
{
    int array1[ SIZE ] = { 5 , 3 , 1 , 2 , 4 };
    printf( "initial array: " );
    printArray( array1 );

    bubbleSort( array1 );

    printf( "array1 after bubble sort: " );
    printArray( array1 );

    return 0;
}

void bubbleSort( int b[] )
{
    int i , hold , pass;
    int a;
    int swapIndicator;

    for ( pass = 1 , a = 1; pass < SIZE; ++pass , ++a ){ //a will size the comparison. each pass, comparison is decreased to avoid non important comparison
        swapIndicator = 0;
        printf( "Pass = %d\n" , pass );
        for ( i = 0; i < SIZE - a; ++i ){
            if ( b[ i ] > b[ i + 1 ] ){
                hold = b[ i ];
                b[ i ] = b[ i + 1 ];
                b[ i + 1 ] = hold;
                swapIndicator = 1; //if swap is happening in a pass, change the value to indicate that
            }//end if
            printf( "comparison %d:" , i + 1 );
            printArray( b );
        }//inner for
        if ( swapIndicator == 0 ){ //if swap value doesn't change/indicate data already in proper order
            printf( "break at pass = %d\n" , pass );
            break;
        }
    }//outer for

}

void printArray( int b[] )
{
    int i;
    for ( i = 0; i < SIZE; ++i ){
        printf( "%3d" , b[ i ] );
    }printf( "\n" );
}
