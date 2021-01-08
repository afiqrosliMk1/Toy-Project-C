//initializing multidimensional array
#include <stdio.h>
void printArray( int b[][ 3 ] );

int main( void )
{
    int array1[ 2 ][ 3 ] = { { 5 , 8 , 0} , { 7 , 6 , 3 } };
    int array2[ 2 ][ 3 ] = { 5 , 4 , 3 , 2 , 8 };
    int array3[ 2 ][ 3 ] = { { 2 , 1 } , { 9 } };

    printArray( array1 );
    printArray( array2 );
    printArray( array3 );

    return 0;
}

void printArray( int b[][ 3 ] )
{
    int i , j;
    for ( i = 0; i < 2; ++i ){
        for ( j = 0; j < 3; ++j ){
            printf( "%3d" , b[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );


}
