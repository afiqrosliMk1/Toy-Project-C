#include <stdio.h>
#include <ctype.h>

int main( void )
{
    char s[ 100 ];
    int i = 0;

    printf( "Enter a line of text: " );
    fgets( s , 100 , stdin );

    printf( "In upper case: \n" );
    for ( i = 0; s[ i ] != '\0'; ++i ){
        printf( "%c" , toupper( s[ i ] ) );
    }

    printf( "In lower case: \n" );
    for ( i = 0; s[ i ] != '\0'; ++i ){
        printf( "%c" , tolower( s[ i ] ) );
    }

    return 0;
}
