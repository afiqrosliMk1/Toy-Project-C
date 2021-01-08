#include <stdio.h>
#include <string.h>
#include <ctype.h>
void printPiglatin( char *sPtr );

int main( void )
{
    char sentence[] = "Break this up";
    char *tokenPtr;

    tokenPtr = strtok( sentence , " " );

    while ( tokenPtr != NULL ){
        printPiglatin( tokenPtr );
        tokenPtr = strtok( NULL , " " );
    }

    return 0;
}

void printPiglatin( char *sPtr )
{
    char temp;
    char prefix[] = "ay";

    temp = tolower( *sPtr );
    memmove( sPtr , &sPtr[ 1 ] , ( strlen( sPtr ) - 1 ) );
    sPtr[ strlen( sPtr ) - 1 ] = temp;
    printf( "%s%s\n" , sPtr , prefix );
}
