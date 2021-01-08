#include <stdio.h>

int main( void )
{
    int number = 2;
    while ( number > 0 ){
        printf( "%d\n" , number *= 2 );
    }

    return 0;
}
