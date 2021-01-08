#include <stdio.h>

int main( void )
{
    int number = 0;
    int counter = 0;
    int sum = 0;

    //printf( "Enter an integer (9999 to end): " );
    scanf( "%d" , &number );

    for ( ; number != 9999 ; ){
        sum += number;
        counter++;
        scanf( "%d" , &number );
    }

    printf( "average = %d" , sum / counter );
    return 0;
}
