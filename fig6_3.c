#include <stdio.h>

int main( void )
{
    int n[ 10 ];
    int i;

    for ( i = 0; i < 10; ++i ){
        n[ i ] = 0;
        printf( "n[%d] = %d\n" , i , n[i] );
    }

    return 0;
}
