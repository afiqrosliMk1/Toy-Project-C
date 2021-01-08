#include <stdio.h>
void characterSquare( int size , char pattern );

int main( void )
{
    int n;
    char fillCharacter;

    printf( "Enter size: " );
    scanf( "%d" , &n );
    printf( "Enter fill character: " );
    scanf( " %c" , &fillCharacter );

    characterSquare( n , fillCharacter );

    return 0;
}

void characterSquare( int size , char pattern )
{
    for ( int i = 1; i <= size; i++ ){
        for ( int j = 1; j <= size; j++ ){
            printf( "%c" , pattern );
        }
        printf( "\n" );
    }
}
