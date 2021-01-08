#include <stdio.h>

int main( void )
{
    int value1 , value2;
    printf( "Enter two integer :" );
    scanf( "%d%d" , &value1 , &value2 );

    if ( value1 == value2 ){
        printf( "These numbers are equal" );
    }

    if ( value1 > value2 ){
        printf( "%d is larger than %d" , value1 , value2 );
    }

    if ( value2 > value1 ){
        printf( "%d is larger than %d" , value2 , value1 );
    }

    return 0;
}
