//duplicate elimination
#include <stdio.h>
void printArray( int b[] , int p );
#define SIZE 4

int main( void )
{
    int storeArray[ SIZE ] = { 0 };
    int num , i = 0 , count , indicator;

    for ( count = 0; count < SIZE; ){
        printf( "Enter a value: " );
        scanf( "%d" , &num );
        indicator = 0;

        for ( i = 0; i < SIZE; ++i ){
            if ( num == storeArray[ i ] ){
                indicator++;
            }
        }
        if ( indicator == 0 ){
            storeArray[ count ] = num;
            ++count;
        }
    }

    printArray( storeArray , SIZE );

    return 0;
}

void printArray( int b[] , int p )
{
    int j;
    for ( j = 0; j < p; ++j ){
        printf( "%3d" , b[ j ] );
    }printf( "\n" );
}
