#include <stdio.h>
void asteriskSquare ( int n );

int main( void )
{
    int size;
    printf( "Enter size: " );
    scanf( "%d" , &size );
    asteriskSquare( size );

    return 0;
}

void asteriskSquare ( int n )
{
    for ( int i = 1; i <= n; i++ ){
        for ( int j = 1; j <= n; j++ ){
            printf( "*" );
        }
        printf( "\n" );
    }
}
