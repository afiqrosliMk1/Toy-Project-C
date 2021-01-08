#include <stdio.h>

int main( void )
{
    int i;

    for ( i = 6; i >= 0; --i ){
        printf( "%.*lf\n" , i , 100.453627 );
    }



    return 0;
}
