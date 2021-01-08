#include <stdio.h>
#include <math.h>
double hypotenuse ( double side1 , double side2 );

int main( void )
{
    double length1 = 0 , length2 = 0;

    for ( int i = 1; i <= 3; i++ ){
        printf( "Enter two lengths: " );
        scanf( "%lf%lf" , &length1 , &length2 );
        printf( "%-12s%-12s%-12s%-12s\n" , "Triangle" , "Length 1" , "Length 2" , "Hypotenuse" );
        printf( "%-12d%-12f%-12f%-12f\n\n" , i , length1 , length2 , hypotenuse( length1 , length2) );
    }

    return 0;
}

double hypotenuse ( double side1 , double side2 )
{
    return pow( ( side1 * side1 + side2 * side2 ) , 0.5 );
}
