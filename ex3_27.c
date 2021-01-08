#include <stdio.h>

int main( void )
{
    int number ,  largest  , second_largest , counter = 10 , intermediate; //intermediate is used to transfer value

    printf( "Enter an integer:" );
    scanf( "%d" , &number );
    counter--;
    largest = number;

    printf( "Enter an integer:" );
    scanf( "%d" , &number );
    counter--;
    if ( number > largest ){
        largest = number;
    }else{
        second_largest = number;
    }

    while ( counter >= 1 ){
        printf( "Enter an integer:" );
        scanf( "%d" , &number );
        counter--;
        if ( number > largest ){
            intermediate = largest;
            largest = number;
            second_largest = intermediate;
        }else if ( number > second_largest ){
            second_largest = number;
        }
    }

    printf( "\n\nLargest is %d" , largest );
    printf( "\nSecond largest is %d\n\n" , second_largest );

    return 0;
}
