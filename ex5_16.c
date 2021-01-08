#include <stdio.h>

int integerPower( int , int );

int main( void )
{
    int x = 4 , y = 2;
    printf( "integerPower( %d , %d ) = %d" , x , y , integerPower( x , y ) );

    return 0;
}

int integerPower( int a , int b )
{
    int value = 1;
    for ( int i = 1; i <= b; i++ ){
        value *= a;
    }
    return value;
}
