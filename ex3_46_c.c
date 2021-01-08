#include <stdio.h>

int main( void )
{
    int factorial , i = 1, j , x , number;
    double epower = 1 , term , xpower;

    printf( "enter value of x to calculate e^x :" );
    scanf( "%d" , &x );
    printf( "enter degree of assumption: " );
    scanf( "%d" , &number );

    while ( i <= number ){
        factorial = 1;
        xpower = 1;
        j = 1;
        while ( j <= i ){
            factorial = factorial * j;
            xpower = xpower * x;
            j++;
        }
        term = xpower / (double)factorial;
        epower = epower + term;
        i++;
    }

    printf( "e^%d (with %dth degree assumption) = %lf" , x , number , epower );

    system( "pause" );
    return 0;
}
