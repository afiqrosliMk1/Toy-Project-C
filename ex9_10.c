#include <stdio.h>

int main( void )
{
    int i;

    for ( i = 0; i <= 10; ++i ){
        printf( "%*d\n" , i , 12345 );
        printf( "%*lf\n\n" , i , 1.2345 );
    }



    return 0;
}
