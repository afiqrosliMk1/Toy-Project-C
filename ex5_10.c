#include <stdio.h>
#include <math.h>

float roundToInteger( float x );

int main( void )
{
    float number = 0;

    printf( "Application Round Number\n\n" );
    printf( "Enter a value (EOF to end):\n" );
    //printf( "Original Number\tRounded Number\n" );

    while ( number != EOF ){
        scanf( "%f" , &number );
        printf( "%f\n" , roundToInteger( number ) );
    }

    return 0;
}

float roundToInteger( float x )
{
    float y;
    y = floor( x + 0.5 );
    return y;
}
