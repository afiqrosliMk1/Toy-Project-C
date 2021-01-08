#include <stdio.h>
#include <string.h>

int main( void )
{
    char letter = 'r';
    const char *sentence = "Selamat Hari Raya Aidilfitri";

    printf( "Remainder of \"%s\" beginning with last occurrence of letter '%c' is %s" ,
            sentence , letter , strrchr( sentence , letter ) );

    return 0;
}
