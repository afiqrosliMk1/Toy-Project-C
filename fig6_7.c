//for fig6_7.c and fig6_8.c
#include <stdio.h>
#define RESPONSE_SIZE 20
#define FREQUENCY_SIZE 11

int main( void )
{
    int response[ RESPONSE_SIZE ] = { 2 , 1 , 3 , 5 , 3 , 5 , 2 ,6 ,7 ,8 , 10 , 2 , 4 , 9 , 3 , 8 , 8 , 5 , 2 , 3 };
    int frequency[ FREQUENCY_SIZE ] = { 0 }; //initialize all elements to zero
    int i , j;

    for ( i = 0; i < RESPONSE_SIZE; ++i ){
        ++frequency[ response[ i ] ];
    }
    printf( "%-15s%-15s%-15s\n" , "response" , "frequency" , "histogram");
    for ( i = 1; i < FREQUENCY_SIZE; ++i ){
        printf( "%-15d%-15d" , i , frequency[ i ] );
            for ( j = 1; j <= frequency[ i ] ; ++j ){
                printf( "*" );
            }printf( "\n" );
    }

    return 0;
}
