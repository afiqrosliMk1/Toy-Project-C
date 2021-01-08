#include <stdio.h>

int main( void )
{
    char str[ 80 ] = { "1324.55" };
    int x;
    double y;

    sscanf( str , "%d%lf" , &x , &y );
    printf( "%s\n%s%d\n%s%8.2lf\n" , "Value read by sscanf:" , "int : " , x , "double : " , y );

    return 0;
}
