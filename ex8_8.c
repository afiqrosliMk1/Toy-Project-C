#include <stdio.h>
#include <stdlib.h>

int main( void )
{
    char s1[ 10 ];
    int i;
    double sum = 0;

    for ( i = 1; i <= 4; ++i ){
        puts( "Enter a floating point string: " );
        fgets( s1 , 10 , stdin );
        sum += atof( s1 );
    }
    printf( "sum = %lf\n" , sum );

    return 0;
}
