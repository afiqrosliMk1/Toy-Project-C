//calculate time in seconds between two times in the same 12 hour cycle of the clock
#include <stdio.h>
#include <math.h>
int timeInSecond ( int hour , int minute , int second );

int main( void )
{
    int h1 , h2 , m1 , m2 , s1 , s2 , amountOfTime;
    printf( "Enter time (hh:mm:ss): " );
    scanf( "%d%d%d" , &h1 , &m1 , &s1 );
    printf( "Enter time (hh:mm:ss): " );
    scanf( "%d%d%d" , &h2 , &m2 , &s2 );

    amountOfTime = timeInSecond( h1 , m1 , s1 ) - timeInSecond( h2 , m2 , s2 );
    printf( "Amount of time is %f seconds" , fabs( (float)amountOfTime ) );

    return 0;
}

int timeInSecond ( int hour , int minute , int second )
{
    return hour * 60 * 60 + minute * 60 + second;
}
