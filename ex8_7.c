#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char s1[ 10 ];
    int i;
    int sum = 0;

    for ( i = 1; i <= 4; ++i ){
        printf( "Enter an integer string: " );
        fgets( s1 , 20 , stdin );
        sum += atoi( s1 );
    }

    printf( "sum = %d\n" , sum );
    /*char s1[ 20 ];
    char s2[ 20 ];
    char s3[ 20 ];
    char s4[ 20 ];
    int d1 = 0 , d2 = 0 , d3 = 0 , d4 = 0;

    printf( "Enter value for s1: " );
    fgets( s1 , 20 , stdin );
    printf( "Enter value for s2: " );
    fgets( s2 , 20 , stdin );
    printf( "Enter value for s3: " );
    fgets( s3 , 20 , stdin );
    printf( "Enter value for s4: " );
    fgets( s4 , 20 , stdin );

    d1 = atoi( s1 );
    d2 = atoi( s2 );
    d3 = atoi( s3 );
    d4 = atoi( s4 );

    printf( "Total = %d\n" , d1 + d2 + d3 + d4 ); */

    return 0;
}
