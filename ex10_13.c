//this exercise combines ex10_13 with ex10_14
#include <stdio.h>
#include <limits.h>

unsigned packCharacters( char *sPtr );
void displayBits( unsigned value );
void unpackCharacters( unsigned value );

int main( void )
{
    char charArray[ 5 ] = { 'w' , 'x' , 'y' , 'z' , '\0' };
    int i;
    unsigned packChar;

    for ( i = 0; charArray[ i ] != '\0'; ++i ){
        printf( "%c = " , charArray[ i ] );
        displayBits( charArray[ i ] );
    }

    printf( "After packing..\n" );
    packChar = packCharacters( charArray );
    displayBits( packChar );

    printf( "Unpacking..\n" );
    unpackCharacters( packChar );

    return 0;
}

unsigned packCharacters( char *sPtr )
{
    //this program packed 4 chars into 4 byte unsigned variable
    unsigned packedC = 0;

    if ( *sPtr != '\0' ){
        packedC = *sPtr;
        sPtr++;
    }
    while ( *sPtr != '\0' ){
        packedC <<= CHAR_BIT;
        packedC = ( packedC | *sPtr );
        sPtr++;
    }

    return packedC;
}

void unpackCharacters( unsigned value )
{
    unsigned mask;
    unsigned temp;
    char a , b , c , d;
    int i;

    for( i = 1; i <= 4; ++i ){

        switch ( i ){
            case 1:
                mask = 0b11111111000000000000000000000000;
                temp = value & mask;
                a = temp >> 24;
                printf( "%c = " , a );
                displayBits( a );
                break;
            case 2:
                mask = 0b111111110000000000000000;
                temp = value & mask;
                b = temp >> 16;
                printf( "%c = " , b );
                displayBits( b );
                break;
            case 3:
                mask = 0b1111111100000000;
                temp = value & mask;
                c = temp >> 8;
                printf( "%c = " , c );
                displayBits( c );
                break;
            case 4:
                mask = 0b11111111;
                temp = value & mask;
                d = temp;
                printf( "%c = " , d );
                displayBits( d );
                break;

        }

    }
}

void displayBits( unsigned value )
{
    unsigned bitmask = 1 << ( CHAR_BIT * sizeof( unsigned ) - 1 );
    int c;

    for ( c = 1; c <= CHAR_BIT * sizeof( unsigned ) ; ++c ){
        putchar( bitmask & value ? '1' : '0' );
        value <<= 1;

        if ( c % 8 == 0 ){
            putchar( ' ' );
        }
    }putchar( '\n' );
}
