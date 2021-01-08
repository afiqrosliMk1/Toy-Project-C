#include <stdio.h>
#include <string.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 100

void printSortedString( char s[][ 100 ] , int size );

int main( void )
{
    char sentences[ ROW_SIZE ][ COLUMN_SIZE ] = { "Charlie" , "Bravo" , "Alpha" , "Echo" , "Delta" };
    char temp[ COLUMN_SIZE ] = "";
    int i = 0;
    int pass;

    for ( i = 0; i < ROW_SIZE; ++i ){
        printf( "Enter string of text: " );
        scanf( "%s" , &sentences[ i ][ 0 ] );
    }

    for ( pass = 1; pass < ROW_SIZE; ++pass ){
        for ( i = 0; i < ROW_SIZE - 1 ; ++i ){
            if ( strcmp( &sentences[ i ][ 0 ] , &sentences[ i + 1 ][ 0 ] ) > 0 ){
                memcpy( temp , &sentences[ i ][ 0 ] , COLUMN_SIZE );
                memmove( &sentences[ i ][ 0 ] , &sentences[ i + 1 ][ 0 ] , COLUMN_SIZE );
                memmove( &sentences[ i + 1 ][ 0 ] , temp , COLUMN_SIZE );
            }
        }
    }
    printSortedString( sentences , ROW_SIZE );

    return 0;
}

void printSortedString( char s[][ COLUMN_SIZE ] , int size )
{
    int i;

    for ( i = 0; i < size; ++i ){
        printf( "%s\n" , &s[ i ][ 0 ] );
    }
}
