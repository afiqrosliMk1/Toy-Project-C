#include <stdio.h>
float minimum( float , float , float );

int main( void )
{
    float f1 , f2 , f3;
    printf( "Enter 3 float values to determine the smallest: " );
    scanf( "%f%f%f" , &f1 , &f2 , &f3 );
    printf( "The minimum value: %f" , minimum( f1 , f2 , f3 ) );
    return 0;
}

float minimum( float a , float b , float c )
{
    float minimumFloat = a;
    if ( b < minimumFloat ){
        minimumFloat = b;
    }
    if ( c < minimumFloat ){
        minimumFloat = c;
    }
    return minimumFloat;
}
