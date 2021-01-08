#include <stdio.h>
#include <string.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 100

int main( void )
{
    char sentences[ ROW_SIZE ][ COLUMN_SIZE ] = { {"bafiqed"} , {"muhammad"} , "rosli" , "bined" , "mar" };
    int i;
    int size;

    for ( i = 0; i < ROW_SIZE; ++i ){
        size = strlen( &sentences[ i ][ 0 ] );
        if ( strcmp( &sentences[ i ][ size - 2 ] , "ed" ) == 0 ){
            printf( "%s\n" , &sentences[ i ][ 0 ] );
        }
    }

    return 0;
}
