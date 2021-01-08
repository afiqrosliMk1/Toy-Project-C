//linear searching
#include <stdio.h>
#define SIZE 100
int linearSearch( int key , int b[] , int arraySize );
void printArray( int b[] , int arraySize );

int main( void )
{
    int a[ SIZE ] = { 0 };
    int i , elementResult;
    int searchKey = 8;

    for ( i = 0; i < SIZE; ++i ){
        a[ i ] = 2 * i;
    }printArray( a , SIZE );

    elementResult = linearSearch( searchKey , a , SIZE );
    if ( elementResult != -1 ){
        printf( "Search key is found at array element %d\n" , elementResult );
    }else{
        printf( "Value not found\n" );
    }

    return 0;
}

int linearSearch( int key , int b[] , int arraySize )
{
    int j;

    for ( j = 0; j < arraySize; ++j ){
        if ( b[ j ] == key ){
            return j;
        }
    }
    return -1;
}

void printArray( int b[] , int arraySize )
{
    int k;

    printf( "array: " );
    for ( k = 0; k < arraySize; ++k ){
        printf( "%d " , b[k] );
    }printf( "\n" );
}
