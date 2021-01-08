#include <stdio.h>

int main( void )
{
    int acc_1 = 101 , acc_2 = 102 , acc_3 = 103;
    float creditLimit_1 = 1000, creditLimit_2 = 2000, creditLimit_3 = 5000;
    float currentBalance_1 = 300 , currentBalance_2 = 1800 , currentBalance_3 = 2500;

    creditLimit_1 /= 2;
    creditLimit_2 /= 2;
    creditLimit_3 /= 2;

    if ( currentBalance_1 > creditLimit_1 ){
        printf( "credit limit for account %d exceeded\n" , acc_1 );
    }
    if ( currentBalance_2 > creditLimit_2 ){
        printf( "credit limit for account %d exceeded\n" , acc_2 );
    }
    if ( currentBalance_3 > creditLimit_3 ){
        printf( "credit limit for account %d exceeded\n" , acc_3 );
    }

    return 0;
}
