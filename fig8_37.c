#include <stdio.h>
#include <string.h>

int main( void )
{
    int i = 0;

    for ( i = 0; i <= 20; ++i ){
        printf( "%02d %s\n" , i , strerror( i ) );
    }

    return 0;
}
