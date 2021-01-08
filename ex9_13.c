#include <stdio.h>

int main( void )
{
    int fahrenheit;
    double celcius;

    printf( "%10s\t%10s\n" , "Fahrenheit" , "Celcius" );

    for ( fahrenheit = 0; fahrenheit <= 212; ++fahrenheit ){
        celcius = 5.0 / 9.0 * ( ( double )fahrenheit - 32 );
        printf( "%10d\t" , fahrenheit );
        printf( "%+10.3lf\n" , celcius );
    }



    return 0;
}
