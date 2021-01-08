#include <stdio.h>

int main( void )
{
    int row = 1;

    while ( row <= 8 ){
        int column = 1;

        while ( column <= 16 ){ // if row is odd, use this while loop
            if ( column % 2 != 0 && row % 2 != 0 ){
                printf( "*" );
            }else if ( column % 2 == 0 && row % 2 != 0 ){
                printf( " " );
            }else if ( column % 2 != 0 && row % 2 == 0 ){
                printf( " " );
            }else{ // if col even and row even
                printf( "*" );
            }

            if ( column / 16 == 1 )
                printf( "\n" );
            column++;
        } //  end odd row loop
        row++;
    }



    return 0;
}
