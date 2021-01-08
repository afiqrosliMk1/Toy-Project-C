#include <stdio.h>

int main( void )
{
    int pi = 3.14159;
    float radius;

    printf( "Enter radius of a circle ( mm ): " );
    scanf( "%f" , &radius );
    printf( "diameter: %.4f ( mm )" , 2 * radius );
    printf( "\ncircumference: %.4f ( mm )" , 2 * pi * radius );
    printf( "\narea: %.4f ( mm ^ 2 )" , pi * radius * radius );
}
