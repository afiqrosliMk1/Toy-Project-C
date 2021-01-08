#include <stdio.h>

int main( void )
{
    int a;
    char c;
    char s[ 10 ];
    scanf( "%i" , &a );
    printf( "%d\n" , a );

    scanf( "%c%s" , &c , s );
    printf( "%c\n" , c );
    printf( "%s\n" , s );

    return 0;
}
