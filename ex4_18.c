#include <stdio.h>

int main( void )
{
    int n1 , n2 , n3 , n4 , n5 , i;

    printf( "Enter 5 integer values : " );
    scanf( "%d%d%d%d%d" , &n1 , &n2 , &n3 , &n4 , &n5 );

    for ( i = 1; i <= n1; i++ ){
        printf( "*" );
    }
    printf( "\n" );
    for ( i = 1; i <= n2; i++ ){
        printf( "*" );
    }
    printf( "\n" );
    for ( i = 1; i <= n3; i++ ){
        printf( "*" );
    }
    printf( "\n" );
    for ( i = 1; i <= n4; i++ ){
        printf( "*" );
    }
    printf( "\n" );
    for ( i = 1; i <= n5; i++ ){
        printf( "*" );
    }
    printf( "\n" );

    return 0;
}
