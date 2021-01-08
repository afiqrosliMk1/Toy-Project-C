#include <stdio.h>
#include <math.h>

int main( void )
{
    double amount;
    double principal = 1000; //original amount invested
    double rate = 0.05; //annual interest rate
    int n; //year

    for ( n = 1; n <= 10; n++ ){
        amount = principal * pow( 1 + rate , n );
        printf( "%.2lf\n" , amount );
    }

    return 0;
}
