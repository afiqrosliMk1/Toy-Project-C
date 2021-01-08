#include <stdio.h>

int main( void )
{
    union integer {
        char c;
        short s;
        int i;
        long b;
    };

    union integer value;

    printf( "%d\n" , sizeof(long) );

    printf( "Enter char value: " );
    scanf( "%c" , &( value.c ) );

    printf( "Enter short value: " );
    scanf( "%hd" , &( value.s ) );

    printf( "Enter int value: " );
    scanf( "%d" , &( value.i ) );

    printf( "Enter long value: " );
    scanf( "%ld" , &( value.b ) );

    //printing values stored in union
    printf( "char c = %c\n" , value.c );
    printf( "short s = %hd\n" , value.s );
    printf( "int i = %d\n" , value.i );
    printf( "long b = %ld\n" , value.b );

    return 0;
}
