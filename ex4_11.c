#include <stdio.h>

int main( void )
{
    int counter , smallest , value , i;
    printf( "How many integer you would like to compare?: " );
    scanf( "%d" , &i );
    scanf( "%d" , &value );
    smallest = value;

    for ( counter = 2; counter <= i; counter++ ){
        scanf( "%d" , &value );
        if ( value < smallest ){
            smallest = value;
        }
    }

    printf( "Smallest = %d" , smallest );
    return 0;
}
