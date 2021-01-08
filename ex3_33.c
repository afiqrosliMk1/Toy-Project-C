#include <stdio.h>

int main( void )
{
    int side , row = 1 , column;
    printf( "Enter side size of a square ( 1 to 20 ):" );
    scanf( "%d" , &side );

    while ( row <= side ){
        column = 1;
        while ( column <= side ){
            printf( "*" );
            column++;
        }
        printf( "\n" );
        row++;
    }


    return 0;
}
