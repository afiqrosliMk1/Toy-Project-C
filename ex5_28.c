#include <stdio.h>

int reverseDigit ( int );

int main( void )
{
    int num = 123456789;
    printf( "reversed = %d" , reverseDigit( num ) );

    return 0;
}

int reverseDigit ( int number )
{
    int reversed = 0 , n , i = 1 , j = 1;

    for ( ; number / i != 0; i *= 10 ){
        n = i;
    }
    for ( ; n >= 1; n /= 10 , j *= 10 ){
        reversed = reversed + ( number / n ) * j;
        number %= n;
    }
    return reversed;
}
