#include <stdio.h>

int main( void )
{
    int number = 0 , first , second , third , fourth , intermediate;

    while ( number / 1000 >= 10 || number / 1000 == 0 ){
        printf( "Enter a four digit integer: ");
        scanf( "%d" , &number );
    }

    first = number % 10;
    number /= 10;
    second = number % 10;
    number /= 10;
    third = number % 10;
    number /= 10;
    fourth = number % 10;
    number /= 10;

    first += 7;
    second += 7;
    third += 7;
    fourth += 7;

    first %= 10;
    second %= 10;
    third %= 10;
    fourth %= 10;

    intermediate = first;
    first = third;
    third = intermediate;
    intermediate = second;
    second = fourth;
    fourth = intermediate;

    //printf( "%d%d%d%d" , fourth , third , second , first );
    number = first + second * 10 + third * 100 + fourth * 1000;
    printf( "%d" , number );

    return 0;
}
