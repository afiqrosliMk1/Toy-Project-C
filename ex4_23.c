#include <stdio.h>
#include <math.h>

// all value in sen ( RM / 100 )
int main( void )
{
    int  amount , principal = 100000 , rate = 5 ; // principal = 100000 sen , rate = 5 percent
    int years , dollar , cent;

    for ( years = 1; years <= 10; years++ ){
        amount = principal * pow ( ( 100 + rate ) , years ) / pow ( 100 , years );
        dollar = amount / 100;
        cent = amount % 100;
        printf( "amount for year %d = %d.%d\n" , years , dollar , cent );
    }

    return 0;
}
