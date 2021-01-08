#include <stdio.h>

int main( void )
{
    for ( int i = 1; i <= 9; ++i ){
        printf( "%.*g\n" , i , 9876.12345 );
    }

    return 0;
}
