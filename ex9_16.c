#include <stdio.h>

int main( void )
{
    int array[ 5 ] = { 0 };
    char *text[ 5 ] = { "Read with %d:" , "Read with %i:" , "Read with %u:" , "Read with %o:" , "Read with %x:" };
    int i;

    printf( "Enter 437 five times: " );
    scanf( "%d%i%u%o%x" , &array[ 0 ] , &array[ 1 ] , &array[ 2 ] , &array[ 3 ] , &array[ 4 ] );

    printf( "%4s%4s%4s%4s%4s\n" , "d" , "i" , "u" , "o" , "x" );


    for ( i = 0; i < 5; ++i ){
        printf( "%s\n%d %i %u %o %x\n" , text[ i ] , array[ i ] , array[ i ] , array[ i ] , array[ i ] , array[ i ] );
    }

    return 0;
}
