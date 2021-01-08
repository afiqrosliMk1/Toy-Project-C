#include <stdio.h>
#include <math.h>

int main( void )
{
    printf( "%.1f" , ceil( -fabs( -8 + floor( -5.5 ) ) ) );

    return 0;
}
