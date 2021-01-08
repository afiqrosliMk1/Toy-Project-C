#include <stdio.h>
#include <string.h>

int main( void )
{
    char sentence[ 100 ] = "";
    char searchString[ 10 ] = "";
    char *searchPtr = NULL;

    printf( "Enter a line of text: " );
    fgets( sentence , 100 , stdin );
    *( strchr( sentence , '\n' ) ) = '\0';

    printf( "Enter a search keyword: " );
    fgets( searchString , 10 , stdin );
    *( strchr( searchString , '\n' ) ) = '\0';

    searchPtr = strstr( sentence , searchString );

    while ( searchPtr != NULL ){
        printf( "%s\n" , searchPtr );
        searchPtr = strstr( searchPtr + 1 , searchString );
    }

    return 0;
}
