#include <stdio.h>
#include <math.h>

int main( void )
{
    int decimalNumber = 7 , octalNumber = 0 , m , n;

    while ( decimalNumber > 0 ){
        for ( m = 0; pow( 8 , m ) <= decimalNumber; m++ ){

        }
        n = m - 1;

        octalNumber += decimalNumber / (int)(pow( 8 , n ) + 0.5) * (int)(pow( 10 , n ) + 0.5);
        decimalNumber = decimalNumber % (int)(pow( 8 , n ) + 0.5);
    }

    printf( "%d" , octalNumber );

    return 0;
}
