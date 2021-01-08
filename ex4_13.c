#include <stdio.h>

int main( void )
{
    int product = 1 , i;

    for ( i = 1; i <= 15; i++ ){
        if ( i % 2 != 0 ){
            product *= i;
        }
    }

    printf( "Product of odd int from 1 to 15 = %d" , product );
    return 0;
}
