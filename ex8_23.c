#include <stdio.h>

#define ROW_SIZE 5
#define COLUMN_SIZE 100

int main( void )
{
    char sentences[ ROW_SIZE ][ COLUMN_SIZE ] = { {"bafiq"} , {"muhammad"} , "rosli" , "bin" , "mar" };
    int i;

    for ( i = 0; i < ROW_SIZE; ++i ){
        if ( sentences[ i ][ 0 ] == 'b' ){
            printf( "%s\n" , &sentences[ i ][ 0 ] );
        }
    }



    return 0;
}
