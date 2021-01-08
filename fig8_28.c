#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *string1 = "morning everyone";
    const char *string2 = "very";

    printf( "The remainder of string1 beginning with the first occurrence of string2 is %s" , strstr( string1 , string2 ) );


    return 0;
}
