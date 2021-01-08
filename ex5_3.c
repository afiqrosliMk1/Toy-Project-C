#include <stdio.h>
#include <math.h>

int main( void )
{
    printf( "sqrt(900.0) is %.1f\n" , sqrt( 900.0 ) );
    printf( "sqrt(9.0) is %.1f\n" , sqrt( 9.0 ) );

    printf( "exp(1.0) is %.6f\n" , exp( 1.0 ) );
    printf( "exp(2.0) is %.6f\n" , exp( 2.0 ) );

    printf( "log( 2.718282 ) is %.1f\n" , log( 2.718282 ) );
    printf( "log( 7.389056 ) is %.1f\n" , log( 7.389056 ) );

    printf( "log10( 1 ) is %.1f\n" , log10( 1 ) );
    printf( "log10( 10 ) is %.1f\n" , log10( 10 ) );
    printf( "log10( 100 ) is %.1f\n" , log10( 100 ) );

    printf( "fabs( 13.5 ) is %.1f\n" , fabs( 13.5 ) );
    printf( "fabs( 0 ) is %.1f\n" , fabs( 0 ) );
    printf( "fabs( -13.5 ) is %.1f\n" , fabs( -13.5 ) );

    printf( "ceil( 9.2 ) is %.1f\n" , ceil( 9.2 ) );
    printf( "ceil( -9.8 ) is %.1f\n" , ceil( -9.8 ) );

    printf( "floor( 9.2 ) is %.1f\n" , floor( 9.2 ));
    printf( "floor( -9.8 ) is %.1f\n" , floor( -9.8 ) );

    printf( "pow( 2 , 7 ) is %.1f\n" , pow( 2 , 7 ) );
    printf( "pow( 9 , 5 ) is %.1f\n" , pow( 9 , .5 ) );

    printf( "fmod( 13.657 , 2.333 ) is %.3f\n" , fmod( 13.657 , 2.333 ) );

    printf( "sin(0.0) is %.1f\n" , sin( 0.0 ) );
    printf( "cos(0.0) is %.1f\n" , cos( 0.0 ) );
    printf( "tan(0.0) is %.1f\n" , tan( 0.0 ) );

    return 0;
}
