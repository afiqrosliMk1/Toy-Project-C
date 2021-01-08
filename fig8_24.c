#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *string1 = "Selamat Hari Raya";
    const char *string2 = "Hi";

    printf( "string1 = %s\nstring2 = %s\n" , string1 , string2 );
    printf( "Length of initial segment of string1 containing no characters from string2 = %u\n\n" , strcspn( string1 , string2 ) );


    return 0;
}
