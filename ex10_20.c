#include <stdio.h>

int mystery( unsigned bits );

int main( void )
{
    unsigned x = 0b1111010110;

    printf( "x = %u\n" , x );
    printf( "result is %d\n" , mystery( x ) );

    return 0;
}

//return 1 if number of 1's in bits are even and 0 otherwise
int mystery( unsigned bits )
{
    unsigned i;
    unsigned mask = 1 << 31;
    unsigned total = 0;

    for ( i = 1; i <= 32; ++i , bits <<= 1 ){
        if ( ( bits & mask ) == mask ){
            ++total;
        }
    }
    return !( total % 2 ) ? 1 : 0;
}
