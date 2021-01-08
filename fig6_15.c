#include <stdio.h>
#define SIZE 5

int main( void )
{
    int a[ SIZE ] = { 3 , 2 , 1 , 0 , 4 };
    int hold , i , pass;

    'for ( pass = 1; pass < SIZE; ++pass ){
        for ( i = 0; i < SIZE - 1; ++i ){
            if ( a[ i ] > a[ i + 1 ] ){
                hold = a[ i ];
                a[ i ] = a[ i + 1 ];
                a[ i + 1 ] = hold;
            }
        }
    }

    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] );
    }printf( "\n" );


    return 0;
}
