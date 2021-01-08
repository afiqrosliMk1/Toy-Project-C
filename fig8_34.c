#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *s = "This is a string";

    printf( "The remainder of s after character 'r' is found is \"%s\"" , memchr( s , 'r' , 18 ) );

    return 0;
}
