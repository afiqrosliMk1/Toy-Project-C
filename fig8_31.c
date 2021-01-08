#include <stdio.h>
#include <string.h>

int main( void )
{
    char s1[ 20 ];
    char s2[] = "Hello world";

    memcpy( s1 , s2 , sizeof( s2 ) / sizeof( s2[ 0 ] ) );
    printf( "s1 = %s\n" , s1 );

    return 0;
}
