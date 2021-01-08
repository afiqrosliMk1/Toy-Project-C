#include <stdio.h>

int main( void )
{
    double e = 1 , term = 0;
    int i = 1, j , number , factorial;

    printf( "Insert an integer to assume the degree of assumption for e: " );
    scanf( "%d" , &number );

    while ( i <= number ){
        j = 1;
        factorial = 1;
        while ( j <= i ){
            factorial = factorial * j;
            j++;
        }
        term = 1 / (double)factorial;
        e = e + term;
        i++;
    }
    printf( "e = %lf" , e );
    return 0;
}
