#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    int i;
    srand( time(NULL) );
    for ( i = 1; i <= 20; i++ ){
        printf( "%d " , rand() % 6 + 1 );
        if ( i % 5 == 0 ){
            printf( "\n" );
        }
    }

    return 0;
}
