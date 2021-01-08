#include <stdio.h>

int main( void )
{
    int factorial = 1 , number , i = 1;
    printf( "Insert a number to know its factorial: " );
    scanf( "%d" , &number );

    while ( i <= number ){
        factorial = factorial * i;
        i++;
    }

    printf( "%d! = %d" , number , factorial );
    return 0;
}
