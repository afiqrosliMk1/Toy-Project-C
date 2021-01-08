#include <stdio.h>
#include <string.h>

int main( void )
{
    char sentence[ 100 ] = "First Second Third";
    char *tokenPtr = NULL;
    int count = 0;

    puts( "Enter a line of text: " );
    fgets( sentence , 100 , stdin );

    *( strchr( sentence , '\n' ) ) = '\0';

    tokenPtr = strtok( sentence , " " );

    while ( tokenPtr != NULL ){
        ++count;
        tokenPtr = strtok( NULL , " \n" );
    }

    printf( "Total words: %d\n" , count );

    return 0;
}
