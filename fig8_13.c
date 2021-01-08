//character and string handling functions from stdio.h
#include <stdio.h>

void reverse( char *const str );

int main( void )
{
    char string1[ 10 ];
    printf( "Enter a string: " );
    fgets( string1 , 10 , stdin );
    reverse( string1 );

    return 0;
}

void reverse( char *const str )
{
    if ( str[ 0 ] == '\0' ){
        return;
    }else{
        reverse( &str[ 1 ] );
        putchar( str[ 0 ] );
    }
}
