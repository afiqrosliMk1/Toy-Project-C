#include <stdio.h>
#include <string.h>

int main( void )
{
    char csrc[ 10 ] = "G i";
    char *dest;
    char *src;

    dest = csrc;
    src = csrc + 2;
    memmove( dest , src , strlen( src ) + 1 );
    printf( "%s " , csrc );

    return 0;
}
