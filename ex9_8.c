#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    int number[ 10 ] = { 0 };
    int i;
    int y = 0;
    int total = 0;

    for ( i = 0; i < 10; ++i ){
        number[ i ] = 1 + rand() % 1000;
        y = printf( "%d" , number[ i ] );
        total += y;
        printf( "\t%d\n" , total );
    }



    return 0;
}
