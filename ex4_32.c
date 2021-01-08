#include <stdio.h>

int main( void )
{
    int i , j , size = 0 , mid;

    while ( size % 2 == 0 ){
        printf( "Insert an odd number to size the triangle: " );
        scanf( "%d" , &size );
    }

    mid = size / 2 + 1;

    for ( i = 1; i <= size; i++ ){
        for ( j = 1; j <= size; j++ ){
            if ( (j > ( mid - i ) && j <= size - ( mid - i )) && (j > ( i - mid ) && j <= size - (i - mid)) ){
                printf( "*" );
            }else{
                printf( " " );
            }
        }
        printf( "\n" );
    }

    return 0;
}
