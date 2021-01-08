#include <stdio.h>
#define SIZE 10

int main( void )
{
    int n[ SIZE ] = { 3 , 4 , 5 , 18 , 21 , 34 , 2 , 32 , 53 };
    int i , total = 0;

    printf( "%-10s%5s\n" , "Element" , "Value " );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%-10d%5d\n" , i , n[ i ] );
    }

    //summing the array elements
    for ( i = 0; i < SIZE; ++i ){
        total += n[ i ];
    }
    printf( "Total: %d" , total );

    return 0;
}
