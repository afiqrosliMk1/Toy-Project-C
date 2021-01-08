#include <stdio.h>

int main( void )
{
    int num;
    printf( "Enter a 5 digit number:" );
    scanf( "%d" , &num );

    printf( "%d " , num / 10000 );
    num = num % 10000;
    printf( "%d " , num / 1000 );
    num = num % 1000;
    printf( "%d " , num / 100 );
    num = num % 100;
    printf( "%d " , num / 10 );
    num = num % 10;
    printf( "%d " , num / 1 );


    return 0;
}
