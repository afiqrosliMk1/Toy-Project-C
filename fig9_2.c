#include <stdio.h>

int main( void )
{
    printf( "d = %d\n" , 500 );
    printf( "i = %i\n" , 500 );
    printf( "d = %d\n" , +500 );
    printf( "d = %d\n" , -500 );
    printf( "hd = %hd\n" , 32000 );
    printf( "ld = %ld\n" , 20000 );
    printf( "o = %o\n" , 8 );
    printf( "u = %u\n" , 500 );
    printf( "u = %u\n" , -500 ); //printing negative value with conversion specifier unsigned is a logic error
    printf( "x = %x\n" , 500 );
    printf( "x = %X\n" , 500 );

    return 0;
}
