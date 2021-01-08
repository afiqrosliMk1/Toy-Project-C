#include <stdio.h>

int main( void )
{
    int base = 100000;
    double amount = 1341.42;
    int i = 0;
    int counter;

    while ( base > amount ){
        ++i;
        base /= 10;
    }

    for ( counter = 1; counter <= i; ++counter ){
        printf( "*" );
    }

    printf( "%*.2lf" , 9 - i , amount );

    return 0;
}
