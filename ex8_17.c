#include <stdio.h>
#include <string.h>

int main( void )
{
    char sentence[ 100 ] = "";
    char searchString[ 10 ] = "";
    char *searchPtr = NULL;
    int count = 0;

    printf( "Enter a line of text: " );
    fgets( sentence , 100 , stdin );
    *( strchr( sentence , '\n' ) ) = '\0';

    printf( "Enter a search keyword: " );
    fgets( searchString , 10 , stdin );
    *( strchr( searchString , '\n' ) ) = '\0';

    searchPtr = strstr( sentence , searchString );

    if ( searchPtr != NULL ){
        while ( searchPtr != NULL ){
            ++count;
            printf( "%s\n" , searchPtr );
            searchPtr = strstr( searchPtr + 1 , searchString );
        }
    }else{
        puts( "**** no match is found ****\n" );
    }
    printf( "total match: %d\n" , count );

    return 0;
}
