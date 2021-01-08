#include <stdio.h>
#include <string.h>

int main( void )
{
    char x[ 20 ] = "Muhammad Afiq Rosli";

    printf( "string before memmove: %s\n" , x );
    printf( "string after memmove: %s\n" , memmove( &x[ 10 ] , &x[ 9 ] , strlen( &x[ 10 ] ) ) );
    puts( x );

    return 0;
}
