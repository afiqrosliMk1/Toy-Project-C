#include <stdio.h>
void separatingDigit( int digit );

int main( void )
{
    int number = 324345 ;
    separatingDigit( number );
    return 0;
}

void separatingDigit( int digit )
{
    int n , quotient;
    for ( int i = 1; ( digit / i > 0 ); i *= 10 ){
        n = i;
    }
    //printf( "%d" , n );
    while ( quotient > 0 ){
        quotient = digit / n;
        printf( "%d  " , quotient );
        digit %= n;
        n /= 10;
    }

}
