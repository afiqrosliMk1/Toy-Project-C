//search character in string using strchr()
#include <stdio.h>
#include <string.h>

int main( void )
{
    const char *string1 = "Hello guys";
    char character1 = 'a';
    char character2 = 'e';

    if ( strchr( string1 , character1 ) != NULL ){
        printf( "'%c' was found in \"%s\"\n" , character1 , string1 );
    }else{
        printf( "'%c' was not found in \"%s\"\n" , character1 , string1 );
    }

    if ( strchr( string1 , character2 ) != NULL ){
        printf( "'%c' was found in \"%s\"\n" , character2 , string1 );
    }else{
        printf( "'%c' was not found in \"%s\"\n" , character2 , string1 );
    }

    return 0;
}
