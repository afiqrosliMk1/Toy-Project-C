#include <stdio.h>

int fibonacci( int i );

int main( void )
{
    int number = 8;
    printf( "fibonacci %d: %d" , number , fibonacci( number ) );

    return 0;
}

int fibonacci( int i )
{
    if ( i == 0 ){
        return 0;
    }else if ( i == 1 ){
        return 1;
    }else{
        return fibonacci( i - 1 ) + fibonacci( i - 2 );
    }
}
