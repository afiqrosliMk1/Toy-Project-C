#include <stdio.h>
#include <string.h>

void printToken( char *sPtr[] );

int main( void )
{
    char sentence[ 30 ] = " ";
    char *tokenPtr;
    char *save[ 10 ];
    int i = 0;

    printf( "Enter a line of text: " );
    fgets( sentence , 30 , stdin );

    *( strchr( sentence , '\n' ) ) = '\0'; //replace newline with null character

    tokenPtr = strtok( sentence , " " );
    save[ i++ ] = tokenPtr;

    while( tokenPtr != NULL ){
        tokenPtr = strtok( NULL , " " );
        save[ i++ ] = tokenPtr;
    }

    printToken( save );

    return 0;
}

void printToken( char *sPtr[] )
{
    if ( sPtr[ 0 ] == NULL ){
        return;
    }else{
        printToken( &sPtr[ 1 ] );
        printf( "%s " , sPtr[ 0 ] );
    }
}
