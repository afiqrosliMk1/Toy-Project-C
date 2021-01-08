#include <stdio.h>

int main( void )
{
    char str[ 80 ];
    int x;
    double y;

    printf( "Enter an integer and a double: " );
    scanf( "%d%lf" , &x , &y );

    sprintf( str , "Integer:%6d\nDouble%8.2lf" , x , y );

    printf( "The formatted input stored in the string is:\n%s" , str );

    return 0;
}
