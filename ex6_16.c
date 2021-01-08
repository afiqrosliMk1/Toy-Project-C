#include <stdio.h>

int main( void )
{
    int sales[ 3 ][ 5 ];
    int i , j , count = 1;

    for ( i = 0; i <= 2; ++i ){
        for ( j = 0; j <= 4; ++j , ++count ){
            sales[ i ][ j ] = 0;
            printf( "%-3d sales[%d][%d] = %d\n" , count , i , j , sales[ i ][ j ] );
        }
    }

    return 0;
}
