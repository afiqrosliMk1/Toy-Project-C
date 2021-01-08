#include <stdio.h>

int main( void )
{
    //float 4 bytes, double 8 bytes, long double 12 bytes

    union floatingPoint {
        float f;
        double d;
        long double x;
    };

    union floatingPoint data;

    printf( "Enter float: " );
    scanf( "%f" , &data.f );

    printf( "Enter double: " );
    scanf( "%lf" , &data.d );

    printf( "Enter long double: " );
    scanf( "%Lf" , &data.x );

    printf( "f = %f\n" , data.f );
    printf( "d = %lf\n" , data.d );
    printf( "x = %Lf\n" , data.x );

    return 0;
}
