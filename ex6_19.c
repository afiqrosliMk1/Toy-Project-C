#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printHeader( void );

int main( void )
{
    int sumArray[ 13 ] = { 0 };
    int die1 , die2 , sum;
    int counter;

    //srand( time(NULL) );
    printHeader();
    for ( counter = 1; counter <= 36000; ++counter ){
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        ++ sumArray[ sum ];
    }

    for ( int i = 2; i < 13; ++i ){
        printf( "%8d" , sumArray[ i ] );
    }printf( "\n" );

    return 0;
}

void printHeader( void )
{
    int i;
    //printf( "     " );
    for ( i = 2; i < 13; ++i ){
        printf( "%8d" , i );
    }printf( "\n");

}
