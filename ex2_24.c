#include <stdio.h>

int main( void )
{
    int value;
    printf( "Insert an integer (-1 to quit): " );
    scanf( "%d" , &value );

    while( value != EOF ){
        if ( value % 2 == 0 ){
            printf( "%d is even\n" , value );
        }else{
            printf( "%d is odd\n" , value );
        }
    printf( "Insert an integer (-1 to quit): " );
    scanf( "%d" , &value );
    }

    return 0;
}
