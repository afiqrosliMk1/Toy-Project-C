#include <stdio.h>
float celciusToFahrenheit ( float c );
float fahrenheitToCelcius ( float f );

int main( void )
{
    printf( "%3s%8s\n" , "C" , "F" );
    for ( int i = 0; i <= 100; i++ ){
        printf( "%3d%8.2f\n" , i , celciusToFahrenheit( i ) );
    }
    printf( "\n" );
    printf( "%3s%8s\n" , "F" , "C" );
    for ( int i = 32; i <= 212; i++ ){
        printf( "%3d%8.2f\n" , i , fahrenheitToCelcius( i ) );
    }

}

float celciusToFahrenheit ( float c )
{
    return 1.8 * c + 32;
}

float fahrenheitToCelcius( float f )
{
    return ( f - 32 ) / 1.8;
}
