#include <stdio.h>

int main( void )
{
    int size, row = 1 , column;

    printf( "Enter size of square: " );
    scanf( "%d" , &size );

    while( row <= size ){
        column = 1;
        if ( row == 1 || row == size ){
            while ( column <= size ){
                printf( "*" );
                column++;
            }
        }else{
            while ( column <= size ){
                if ( column == 1 || column == size ){
                    printf( "*" );
                }else{
                    printf( " " );
                }
                column++;
            }
        }

        printf( "\n" );
        row++;
    }

    return 0;
}
