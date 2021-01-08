#include <stdio.h>
// this program determines if the first value is a multiple of second value
int main( void )
{
    int value1 , value2 , quotient;
    printf( "Enter 2 integers: " );
    scanf( "%d%d" , &value1 , &value2 );

    quotient = value2 / value1;
    if( value2 % value1 == 0 ){
        printf( "%d is a multiple of %d\n" , value2 , value1 );
        printf( "%d x %d = %d" , value1 , quotient , value2 );
    }else{
        printf( "%d is not a multiple of %d\n" , value2 , value1 );
    }

    return 0;
}
