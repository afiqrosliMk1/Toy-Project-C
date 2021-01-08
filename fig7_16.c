#include <stdio.h>

size_t getSize( int *ptr );

int main( void )
{
    int a[ 5 ];

    printf( "size of array a is %d\n" , sizeof( a ) );
    printf( "size of each element of array a is %d\n" , getSize( a ) );

    return 0;
}

size_t getSize( int *ptr )
{
    return sizeof( *ptr );
}
