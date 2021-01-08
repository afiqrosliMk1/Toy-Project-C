#include <stdio.h>

int main( void )
{
    int number ;
    long counter = 0;
    printf( "Enter number: " );
    scanf( "%d" , &number );

    while ( number != 0 ){
        if ( number % 10 == 7 ){
        counter++;
        }
        number /= 10;
    }

    printf( "Number of 7: %ld" , counter );
    return 0;
}
