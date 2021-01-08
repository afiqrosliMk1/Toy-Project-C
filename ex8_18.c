#include <stdio.h>
#include <string.h>

int main( void )
{
    char sentence[ 100 ] = "";
    char searchCharacter;
    char *searchPtr = NULL;
    int count = 0;

    printf( "Enter a line of text: " );
    fgets( sentence , 100 , stdin );
    *( strchr( sentence , '\n' ) ) = '\0';

    printf( "Enter a search character: " );
    searchCharacter = getchar();

    searchPtr = strchr( sentence , searchCharacter );

    if ( searchPtr != NULL ){
        while ( searchPtr != NULL ){
            ++count;
            printf( "%s\n" , searchPtr );
            searchPtr = strchr( searchPtr + 1 , searchCharacter );
        }
    }else{
        puts( "**** no match is found ****\n" );
    }
    printf( "total match: %d\n" , count );

    return 0;
}
