#include <stdio.h>

int main( void )
{
    const int pi = 3.14159;
    float radius;

    printf( "Insert radius of a circle: " );
    scanf( "%f" , &radius );

    printf( "\nDiameter: %f" , 2 * radius );
    printf( "\nCircumference: %f" , 2 * pi * radius );
    printf( "\nArea: %f" , pi * radius * radius );

    return 0;
}
