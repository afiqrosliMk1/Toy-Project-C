#include <stdio.h>

int counter = 1;

int main( void )
{
    while ( counter <= 100 ){
        printf( "*" );
        if ( counter % 10 == 0 ){
            printf( "\n" );
        }
        counter++;
    }

    return 0;
}
