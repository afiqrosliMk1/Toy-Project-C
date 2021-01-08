#include <stdio.h>
void automaticArrayInit( void );
void staticArrayInit( void );

#define SIZE 3

int main( void )
{
    //first call
    printf( "FIRST CALL\n" );
    automaticArrayInit();
    staticArrayInit();

    //second call
    printf( "SECOND CALL\n" );
    automaticArrayInit();
    staticArrayInit();
    return 0;
}

void automaticArrayInit( void )
{
    int i;
    int a[ SIZE ] = { 0 };
    printf( "values on entering function automaticArrayInit\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] );
    }printf( "\n" );

    printf( "values on exiting function automaticArrayInit\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , a[ i ] += 5 );
    }printf( "\n" );
}

void staticArrayInit( void )
{
    int i;
    static int b[ SIZE ]; //static array automatically initialized to zero
    printf( "values on entering function staticArrayInit\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , b[ i ]n );
    }printf( "\n" );

    printf( "values on exiting function staticArrayInit\n" );
    for ( i = 0; i < SIZE; ++i ){
        printf( "%d " , b[ i ] += 5 );
    }printf( "\n" );
}
