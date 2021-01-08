#include <stdio.h>

int main( void )
{
    float a[ 3 ];
    char *text[ 3 ] = { "print with %e" , "print with %f" , "print with %g" };

    printf( "Enter value 1.2345 three times: " );
    scanf( "%e%f%g" , &a[ 0 ] , &a[ 1 ] , &a[ 2 ] );

    printf( "%s\n%e\n" , text[ 0 ] , a[ 0 ] );
    printf( "%s\n%f\n" , text[ 1 ] , a[ 1 ] );
    printf( "%s\n%g\n" , text[ 2 ] , a[ 2 ] );

    return 0;
}
