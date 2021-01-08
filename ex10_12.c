#include <stdio.h>
#include <limits.h>

unsigned power2( unsigned originalNumber , unsigned rightOperand );
void displayBits( unsigned value );

int main( void )
{
    unsigned num = 5;
    unsigned exp = 3;
    unsigned result;

    result = power2( num , exp );
    printf( "%u: " , num );
    displayBits( num );

    printf( "%u << %u = " , num , exp );
    displayBits( result );
    printf( "= %u\n" , result );

    printf( "equivalent to: %u * 2power%u = %u" , num , exp , result );

    return 0;
}

unsigned power2( unsigned originalNumber , unsigned rightOperand )
{
    //this function calculates the value of original number after left shifted by "right operand"
    return originalNumber << rightOperand;
}

void displayBits( unsigned value )
{
    unsigned bitmask = 1 << ( CHAR_BIT * sizeof( unsigned ) - 1 );
    int c;

    for ( c = 1; c <= CHAR_BIT * sizeof( unsigned ); ++c ){
        putchar( ( bitmask & value )? '1' : '0' );
        value <<= 1;
        if ( c % 8 == 0 ){
            putchar( ' ' );
        }
    }putchar( '\n' );



}
