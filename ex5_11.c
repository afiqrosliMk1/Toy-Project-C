#include <stdio.h>
#include <math.h>
float rountToInteger( float );
float roundToTenths( float );
float rountToHundredths( float );
float roundToThousandsth( float );

int main( void )
{
    float x = 0;
    while ( x != EOF ){
        printf( "Enter a number: " );
        scanf( "%f" , &x );

        printf( "%8s\t%8s\t%8s\t%8s\t%8s\n" , "Original" , "Integer" , "Tenths" ,
               "Hundredths" , "Thousandths" );
        printf( "%8f\t%8f\t%8f\t%8f\t%8f\n" , x , rountToInteger( x ) ,
               roundToTenths( x ) , rountToHundredths( x ) , roundToThousandsth( x ) );
    }

    return 0;
}

float rountToInteger( float x )
{
    return floor( x + 0.5 );
}

float roundToTenths( float x )
{
    return floor( x * 10 + 0.5 ) / 10;
}

float rountToHundredths( float x )
{
    return floor( x * 100 + 0.5 ) / 100;
}

float roundToThousandsth( float x )
{
    return floor( x * 1000 + 0.5 ) / 1000;
}
