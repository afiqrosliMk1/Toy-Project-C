#include <stdio.h>

int main( void )
{
    int counter = 1;

    while ( counter <= 300000000 ){
        if ( counter % 100000000 == 0 ){
            printf( "%d" , counter );
        }
        counter++;
    }

    return 0;
}
