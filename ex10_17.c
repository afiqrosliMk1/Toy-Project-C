#include <stdio.h>
#include <limits.h>

unsigned reverseBit( unsigned value );
void displayBit( unsigned value );

int main( void )
{
    unsigned val;
    val = reverseBit( 0b11010001 );
    displayBit( val );

    return 0;
}

unsigned reverseBit( unsigned value )
{
    unsigned rBit = 0;
    unsigned mask = 1;
    int i;

    for ( i = 1; i <= CHAR_BIT * sizeof( unsigned ); ++i ){
        rBit <<= 1;
        rBit |= value & mask;
        value >>= 1;
    }

    return rBit;
}

void displayBit( unsigned value )
{
    unsigned mask = 1 << ( CHAR_BIT * sizeof( unsigned ) - 1 );
    int c;

    for ( c = 1; c <= CHAR_BIT * sizeof( unsigned ); ++c ){
        putchar( value & mask ? '1' : '0' );
        value <<= 1;
        if ( c % 8 == 0 ){
            putchar( ' ' );
        }
    }putchar( '\n' );
}
