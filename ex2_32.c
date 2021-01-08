#include <stdio.h>

int main( void )
{
    float bmi , weight , height;
    printf( "insert weight(kg): " );
    scanf( "%f" , &weight );
    printf( "\ninsert height(m):" );
    scanf( "%f" , &height );

    bmi = weight / ( height * height );
    printf( "\nBMI: %.2f\n" , bmi );

    printf( "BMI VALUES\n" );
    printf( "Underweight : Less than 18.5\n" );
    printf( "Normal : Between 18.5 and 24.9\n" );
    printf( "Overweight : Between 25 and 29.9\n" );
    printf( "Obese : 30 or greater\n" );


    return 0;
}
