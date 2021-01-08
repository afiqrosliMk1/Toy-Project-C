//sum array recursively
#include <stdio.h>
#define SIZE 10

int sumArray( int b[] , int p );

int main( void )
{
    int x;
    int a[ SIZE ] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 };

    x = sumArray( a , SIZE );
    printf( "Result is %d\n" , x );

    return 0;
}

int sumArray( int b[] , int p )
{
    if ( p == 1 ){ //base case
       return b[ 0 ];
    }else{ //recursive step
        return b[ p - 1 ] + sumArray( b , p - 1 );
    }
}
