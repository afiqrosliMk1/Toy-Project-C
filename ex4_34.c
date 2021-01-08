#include <stdio.h>

int main( void )
{
    int counter = 1;

    while( counter <= 10 ){
        printf( "%d " , counter );
        counter++;
    }
    printf( "\n" );

    counter = 1;
    do {
        printf( "%d " , counter );
    }while( counter++ < 10 );

    return 0;
}
