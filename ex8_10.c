#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    char s1[ 20 ];
    char s2[ 20 ];
    int n;

    printf( "Enter first string: " );
    scanf( "%s" , s1 );

    printf( "Enter second string: " );
    scanf( "%s" , s2 );

    printf( "Enter number of characters to be compared: " );
    scanf( "%d" , &n );

    printf( "s1 = %s\ns2 = %s\n" , s1 , s2 );

    if ( strncmp( s1 , s2 , n ) > 0 ){
        printf( "\"%s\" is greater than \"%s\" up to %d characters\n" , s1 , s2 , n );
    }else if ( strncmp( s1 , s2 , n ) == 0 ){
        printf( "\"%s\" is equal to \"%s\" up to %d characters\n" , s1 , s2 , n );
    }else{
        printf( "s2 is greater than s1" );
    }

    return 0;
}
