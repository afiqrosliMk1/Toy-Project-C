#include <stdio.h>

int main( void )
{
    int x = 1 , y = 2 , a = 3 , b = 4 , i = 5 , j = 6 , g = 7;

    printf( "%d\n" , !( x < 5 ) && !( y >= 7 ) );
    printf( "%d\n\n" , !( ( x < 5 ) || ( y >= 7 ) ) );

    printf( "%d\n" , !( a == b ) || !( g != 5 ) );
    printf( "%d\n\n" , !( a == b && g != 5 ) );

    printf( "%d\n" , !( ( x <= 8 ) && ( y > 4 ) ) );
    printf( "%d\n\n" , !( x <= 8 ) || !( y > 4 ) );

    printf( "%d\n" , !( ( i > 4 ) || ( j <= 6 ) ) );
    printf( "%d\n\n" , !( i > 4 ) && !( j <= 6 ) );

    return 0;
}
