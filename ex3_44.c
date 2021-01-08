#include <stdio.h>

int main( void)
{
    float a , b , c , max;
    printf( "enter 3 sides to know if they can represent a triangle: " );
    scanf( "%f%f%f" , &a , &b , &c );

    max = a;
    if ( b > a ){
        max = b;
    }
    if ( c > max ){
        max = c;
    }

    if ( a + b + c > 2 * max ){
        printf( "Yes it can " );
    }else{
        printf( "No it can't" );
    }
}
