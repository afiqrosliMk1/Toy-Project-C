#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int face[ 7 ] = { 0 };
    int i;

    srand( time(NULL) );

    for ( i = 1; i <= 6000; ++i ){
        ++face[ rand() % 6 + 1 ];
    }

    for ( i = 0; i < 7; ++i ){
        printf( "face[%d] = %d\n" , i , face[ i ] );
    }

    return 0;
}
