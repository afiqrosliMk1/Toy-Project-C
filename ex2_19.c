#include <stdio.h>

int main( void )
{
    int value1 , value2 , value3;
    int sum , average , product;

    printf( "Input three integer:" );
    scanf( "%d%d%d" , &value1 , &value2 , &value3 );

    sum = value1 + value2 + value3;
    average = sum / 3;
    product = value1 * value2 * value3;

    printf( "Sum is %d\n" , sum );
    printf( "Average is %d\n" , average );
    printf( "Product is %d\n" , product );

    int largest = value1;
    if ( value2 > value1 ){
        largest = value2;
    }
    if ( value3 > value2 ){
        largest = value3;
    }

    printf( "%d is largest\n" , largest );

    int smallest = value1;
    if ( value2 < value1 ){
        smallest = value2;
    }
    if ( value3 < value2){
        smallest = value3;
    }

    printf( "%d is smallest\n" , smallest );
    return 0;
}
