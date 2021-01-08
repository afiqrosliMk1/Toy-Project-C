#include <stdio.h>

int main( void )
{
    printf( "%10s%10d%10c%10f\n\n" , "hello" , 7 , 'a' , 1.24 );//right justified
    printf( "%-10s%-10d%-10c%-10f\n\n" , "hello" , 7 , 'a' , 1.24 );//left justified

    printf( "% d % d\n" , 20 , -20 );
    printf( "%+d %+d\n" , 20 , -20 );

    int c = 1427;
    double p = 123.22;

    printf( "%#o\n" , c );
    printf( "%#x\n" , c );
    printf( "%#X\n" , c );
    printf( "\n%g\n" , p );
    printf( "%#g\n" , p );

    return 0;
}
