#include <stdio.h>

int main( void )
{
    char string[ 3 ][ 20 ] = { "" };
    int i;

    printf( "Enter string three times: " );
    for ( i = 0; i < 3; ++i ){
        scanf( "%s" , &string[ i ][ 0 ] );
    }

    for ( i = 0; i < 3; ++i ){
        printf( "%s" , &string[ i ][ 0 ] );
    }

    return 0;
}
