//string handling library
#include <stdio.h>
#include <stdlib.h>

int main( void )
{

    double n;
    int m;
    long int o;
    const char *string1 = "99% discount sale";
    const char *string2 = "1% rate";
    const char *string3 = "70 out of 10";
    double x;
    long y;
    unsigned long z;
    char *stringPtr1;
    char *remainPtr;
    char *strtoulPtr;

    //convert string to floating point(double)
    n = atof( "13.25" );
    printf( "string after converted to double : %lf\n" , n );
    //convert string to int(4 bytes)
    m = atoi( "21.225" );
    printf( "string after converted to int : %d\n" , m );
    //convert string to long int(4 bytes)
    o = atol( "423.2" );
    printf( "string after converted to long : %ld\n" , o );

    x = strtod( string1 , &stringPtr1 );
    printf( "\nstring1 after conversion to double : %lf\n" , x );
    printf( "\"%s\" %s\n" , stringPtr1 , "is admitted" );

    y = strtol( string2 , &remainPtr , 1 );
    printf( "\nstring2 after conversion to long : %ld\n" , y );
    printf( "\"%s\" %s\n" , remainPtr ,  "is admitted" );

    z = strtoul( string3 , &strtoulPtr , 1 );
    printf( "\nstring3 after conversion to unsigned long : %lu\n" , z );
    printf( "\"%s\" %s" , strtoulPtr , "is admitted" );
    return 0;
}
