#include <stdio.h>

int main( void )
{
    char string1[] = "Muhammad";
    char string2[ 20 ];
    int i;

    printf( "Enter string for char array: " );
    scanf( "%19s" , string2 );

    printf( "string1 = %s\n" , string1 );
    printf( "string2 = %s\n" , string2 );

    printf( "string1 with spaces = " );
    for ( i = 0; string1[ i ] != '\0'; ++i ){
        printf( "%c " , string1[ i ] );
    }

    return 0;
}
