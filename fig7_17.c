//determine size of data types on this system using sizeof operator
#include <stdio.h>

int main( void )
{
    char c;
    int i;
    short s;
    long l;
    float f;
    double d;
    long double ld;
    int array[ 20 ];
    int *ptr = array;

    printf( "size of c = %d\n" , sizeof( c ) );
    printf( "size of i = %d\n" , sizeof( i ) );
    printf( "size of s = %d\n" , sizeof( s ) );
    printf( "size of l = %d\n" , sizeof( l ) );
    printf( "size of f = %d\n" , sizeof( f ) );
    printf( "size of d = %d\n" , sizeof( d ) );
    printf( "size of ld = %d\n" , sizeof( ld ) );
    printf( "size of array = %d\n" , sizeof( array ) );
    printf( "size of each array element = %d\n" , sizeof( *ptr ) );

    return 0;
}
