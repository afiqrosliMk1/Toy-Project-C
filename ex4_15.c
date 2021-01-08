#include <stdio.h>
#include <math.h>

int main( void )
{
    float amount , principal = 1000 , rate = 0.05 ;
    int years;

    for ( ; rate <= 0.10; rate += 0.01 ){
        printf( "Rate = %.2f\n-----------------\n" , rate );
        for ( years = 1; years <= 10; years++ ){
            amount = principal * pow ( ( 1 + rate ) , years );
            printf( "amount for year %d = %.2f\n" , years , amount );
        }
    }

    return 0;
}
