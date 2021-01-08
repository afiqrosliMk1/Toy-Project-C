#include <stdio.h>

int main( void )
{
    int c;

    //puts( "Enter an ASCII code ( 0-255 ): " );
    //scanf( "%d" , &c );

    /*if ( c >= 0 && c <= 255 ){
        printf( "%c" , c );
    }*/

    for ( c = 0; c <= 255; ++c ){
        printf( "%3c" , c );
        if ( c % 10 == 0 && c > 0 ){
            printf( "\n" );
        }
    }

    return 0;
}
