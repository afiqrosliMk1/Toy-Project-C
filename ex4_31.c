#include <stdio.h>

int main( void )
{
    int i , j;

    for ( i = 1; i <= 5; i++ ){
        for ( j = 1; j <= 9; j++ ){
            if ( j > ( 5 - i ) && j < ( 5 + i ) ){
                printf( "*" );
            }else{
                printf( " " );
            }
        }
        printf( "\n" );
    }
    for ( ; i > 5 && i <= 9; i++ ){
        for ( j = 1; j <= 9; j++ ){
            if ( j > ( i - 5 ) && j <= 9 - (i-5) ){
                printf( "*" );
            }else{
                printf( " " );
            }
        }
        printf( "\n" );
    }

    return 0;
}
