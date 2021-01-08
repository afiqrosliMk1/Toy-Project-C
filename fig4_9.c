#include <stdio.h>

int main( void )
{
    int counter = 10;

    do{
        printf( "%d" , counter );
        counter++;
    }while  ( counter <= 1 );

    return 0;
}
