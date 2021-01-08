#include <stdio.h>

int main( void )
{
    int number;
    int sum = 0;
    int counter;
    int value;

    printf( "Enter number of values: " );
    scanf( "%d" , &number );

    for ( counter = 1; counter <= number; counter++ ){
        scanf( "%d" , &value );
        sum += value;
    }

    printf( "sum = %d" , sum );
    return 0;
}
