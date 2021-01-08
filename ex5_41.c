//program that calculate distance between two coordinate points
#include <stdio.h>
#include <math.h>
double distancePoints( double x1 , double y1 , double x2 , double y2 );

int main( void )
{
    double x1 , y1 , x2 , y2;
    printf( "Insert first point ( x1 , y1 ): " );
    scanf( "%lf%lf" , &x1 , &y1 );
    printf( "Insert first point ( x2 , y2 ): " );
    scanf( "%lf%lf" , &x2 , &y2 );

    printf( "Distance = %lf\n" , distancePoints( x1 , y1 , x2 , y2 ) );

    return 0;
}

double distancePoints( double x1 , double y1 , double x2 , double y2 )
{
    int a , b , c;
    a = x1 - x2;
    b = y1 - y2;
    c = pow( a , 2 ) + pow( b , 2 );
    return pow ( c , 0.5 );
}
