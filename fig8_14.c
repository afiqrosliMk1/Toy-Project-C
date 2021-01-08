#include <stdio.h>

int main( void )
{
    char sentence[ 30 ];
    int i = 0;
    printf( "Enter a line of words: " );

    while ( ( sentence[ i ] = getchar() ) != '\n' ){
        ++i;
    }sentence[ i ] = '\0';

    puts( sentence );

    return 0;
}
