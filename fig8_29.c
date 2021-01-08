#include <stdio.h>
#include <string.h>

int main( void )
{
    char sentence[] = "   Selamat    Hari Raya";
    char *tokenPtr;

    printf( "%s\n%s\n" , "The string to be tokenized is:" , sentence );
    printf( "The tokens are:\n" );

    tokenPtr = strtok( sentence , " " );

    while ( tokenPtr != NULL ){
        printf( "%s\n" , tokenPtr );
        tokenPtr = strtok( NULL , " " );
    }

    return 0;
}
