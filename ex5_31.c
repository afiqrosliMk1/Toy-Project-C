#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int flip( void );

int main( void )
{
    int counter = 1 , head = 0 , tail = 0;

    srand( time(NULL) );

    while ( counter <= 1000 ){
        switch ( flip () ){
            case 1:
                head++;
                break;
            case 0:
                tail++;
                break;
        }
        counter++;
    }//end while
    printf( "Head: %d\n" , head );
    printf( "Tail: %d\n" , tail );
    return 0;
}

int flip( void )
{
    return ( rand() % 2 );
}
