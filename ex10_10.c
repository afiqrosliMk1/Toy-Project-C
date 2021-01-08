#include <stdio.h>
#include <limits.h>

void displayBits( int value );

int main( void )
{
    int a = 3;

    displayBits( a );
    displayBits( a >> 4 );

    return 0;
}

void displayBits( int value )
{
    int bitMask = 1 << ( CHAR_BIT * sizeof( int ) - 1 ); //left shift 31 bits
    int c;

    for ( c = 1; c <= CHAR_BIT * sizeof( int ); ++c ){
        putchar( ( value & bitMask )? '1' : '0' );
        value <<= 1;

        if ( c % 8 == 0 ){
            putchar( ' ' );
        }
    }putchar( '\n' );

}
