//finding prime number using method of sieve of erathosthenes
#include <stdio.h>

#define SIZE 1000

void printSubscript( int array[] );

int main( void )
{
    int number[ SIZE ];
    int i , j;

    //initialize all values in array to 1
    for ( i = 0; i < SIZE; ++i ){
        number[ i ] = 1;
    }

    for ( i = 2; i < SIZE; ++i ){
        if ( number[ i ] == 1 ){
            for ( j = i + 1; j < SIZE; ++j ){
                if ( j % i == 0 ){
                    number[ j ] = 0;
                }
            }
        }
    }

    printSubscript( number );

    return 0;
}

void printSubscript( int array[] )
{
    int i;
    int counter = 0;
    for ( i = 1; i < SIZE; ++i ){
        if ( array[ i ] == 1 ){
            printf( "%4d" , i );
            ++counter;
            if ( counter % 20 == 0 ){
                printf( "\n" );
            }
        }

    }printf( "\n" );
    printf( "There are %d prime numbers in %d to %d" , counter , 1 , SIZE );

}
