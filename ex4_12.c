#include <stdio.h>

int main( void )
{
    int i , sum = 0;

    for ( i = 2; i <= 5; i++ ){
        if ( i % 2 == 0 ){
            sum += i;
        }
    }

    printf( "Sum of even integer: %d" , sum );

    return 0;
}
