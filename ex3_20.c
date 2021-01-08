#include <stdio.h>

int main( void )
{
    float principal , rate , interest;
    int days;

    printf( "Enter loan principal ( -1 to end ):" );
    scanf( "%f" , &principal );

    while ( principal != EOF ){
        printf( "Enter interest rate:" );
        scanf( "%f" , &rate );
        printf( "Enter term of the loan in days:" );
        scanf( "%d" , &days );

        interest = principal * rate * days / 365;
        printf( "The interest charge is: $%.2f" , interest );

        printf( "\n\nEnter loan principal ( -1 to end ):" );
        scanf( "%f" , &principal );
    }

    return 0;
}
