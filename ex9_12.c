#include <stdio.h>

int main( void )
{
    char text[ 20 ] = "";
    int fieldWidth;

    printf( "input string: " );
    scanf( "%s%n" , text , &fieldWidth );

    printf( "%*s" , 2 * fieldWidth , text );

    return 0;
}
