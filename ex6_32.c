//linear searching: recursive approach
#include <stdio.h>
#define SIZE 100

int linearSearch( int key , int b[] , int low , int high );
void printArray( int b[] , int arraySize );

int main( void )
{
    int a[ SIZE ] = { 0 };
    int i , elementResult;
    int searchKey = 8;

    for ( i = 0; i < SIZE; ++i ){
        a[ i ] = 2 * i;
    }printArray( a , SIZE );

    elementResult = linearSearch( searchKey , a , 0 , SIZE - 1 );
    if ( elementResult != -1 ){
        printf( "Search key is found at array element %d\n" , elementResult );
    }else{
        printf( "Value not found\n" );
    }

    return 0;
}

int linearSearch( int key , int b[] , int low , int high )
{
   if ( b[ low ] == key ){
        return low;
   }else if ( low == high ){
        return -1;
   }else{
        return linearSearch( key , b , low + 1 , high );
   }
}

void printArray( int b[] , int arraySize )
{
    int k;

    printf( "array: " );
    for ( k = 0; k < arraySize; ++k ){
        printf( "%d " , b[k] );
    }printf( "\n" );

}
