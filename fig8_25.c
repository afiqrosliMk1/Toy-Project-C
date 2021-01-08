#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *string1 = "Selamat hari raya";
    const char *string2 = "selamat hari raya";

    printf( "of the characters in \"%s\" , %c appears earliest in \"%s\"\n" , string2 , *strpbrk( string1 , string2 ) , string1 );

    return 0;
}
