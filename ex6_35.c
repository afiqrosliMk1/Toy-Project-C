//print an array
#include <stdio.h>
#define SIZE 5

void printArray( int a[] , int low , int high );

int main( void )
{
    int array[ SIZE ] = { 2 , 5 , 7 , 9 , 10 };
    printArray( array , 0 , SIZE - 1 );

    return 0;
}

void printArray( int a[] , int low , int high )
{
    printf( "%3d" , a[ low ] );
    if ( low == high ){
        return;
    }else{
        printArray( a , low + 1 , high );
    }
}
