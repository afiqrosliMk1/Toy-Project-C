#include <stdio.h>

int main( void )
{
    char string1[ 25 ];
    printf( "Enter a string: " );
    scanf( "%24s" , string1 );
    printf( "%s" , string1 );
    printf( "%d" , string1[ 0 ] );

    return 0;
}
