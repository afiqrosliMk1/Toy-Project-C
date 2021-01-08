#include <stdio.h>

int main( void )
{
    int counter = 5;
    int number , largest;

    printf( "Enter an integer: " );
    scanf( "%d" , &number );

    largest = number;
    counter--;
    while ( counter >= 1 ){
        printf( "Enter an integer: " );
        scanf( "%d" , &number );

        if ( number > largest ){
            largest = number;
        }
        counter--;
    }

    printf( "The largest number is %d" , largest );
    return 0;
}
