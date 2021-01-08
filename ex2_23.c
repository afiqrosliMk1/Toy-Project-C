#include <stdio.h>
//this program inputs 5 integers and determine which one is smallest and largest
int main( void )
{
    int num1 = 0 , num2  = 0 , num3 = 0 , num4 = 0 , num5 = 0;
    int largest , smallest;

    printf( "Enter 5 integers: " );
    scanf( "%d%d%d%d%d" , &num1 , &num2 , &num3 , &num4 , &num5 );

    largest = num1;
    if ( num2 > num1 ){
        largest = num2;
    }

    if ( num3 > num2 ){
        largest = num3;
    }

    if ( num4 > num3 ){
        largest = num4;
    }

    if ( num5 > num4 ){
        largest = num5;
    }

    printf( "%d is Largest\n" , largest );

    smallest = num1;
    if ( num2 < num1 ){
        smallest = num2;
    }

    if ( num3 < num2 ){
        smallest = num3;
    }

    if ( num4 < num3 ){
        smallest = num4;
    }

    if ( num5 < num4 ){
        smallest = num5;
    }

    printf( "%d is Smallest\n" , smallest );
    return 0;
}
