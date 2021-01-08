//this program demonstrate the capabilities of break and continue
#include <stdio.h>

int main( void )
{
    int counter;

    for ( counter = 0; counter <= 10; counter++ ){
        if ( counter % 2 == 0 ){
            continue;
        }
        printf( "%d " , counter );
    }

    return 0;
}
