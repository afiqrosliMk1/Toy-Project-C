#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *string1 = "sePlamat pagi";
    const char *string2 = "elsa";

    printf( "string1 = %s\n" , string1 );
    printf( "string2 = %s\n" , string2 );
    printf( "The length of initial segment of string1 containing only the characters from string2 = %u" , strspn( string1 , string2 ) );

    return 0;
}
