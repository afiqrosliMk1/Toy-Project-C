//printing string backwards
#include <stdio.h>

#define SIZE 30

void stringReverse( char str[] );

int main( void )
{
    int n = 0;
    char string[ SIZE ] = "abcdef\0XYZ";

    //just to show array values
    while ( n < SIZE ){
        printf( "%c" , string[ n ] );
        ++n;
    }printf( "\n" );
    //
    b
    stringReverse( string );




    return 0;
}

void stringReverse( char str[] )
{
    if ( str[ 0 ] == '\0' ){
        return;
    }
    stringReverse( &str[ 1 ] );
    printf( "%c" , str[ 0 ] );

}

