#include <stdio.h>
#include <math.h>
int main( void )
{
    int binaryNum , remainder , decimalNum = 0 , exponent = 0;
    printf( "Enter a binary number: " );
    scanf( "%d" , &binaryNum );

    while ( binaryNum != 0 ){
        remainder = binaryNum % 10;
        binaryNum = binaryNum / 10;
        decimalNum = decimalNum + remainder * pow( 2 , exponent );
        exponent++;
    }

    printf( "Decimal equivalent of this: %d" , decimalNum );
    return 0;
}
