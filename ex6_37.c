#include <stdio.h>
#define SIZE 5

int recursiveMin( int a[] , int low , int high );

int main( void )
{
    int val[ SIZE ] = { 8 , 2 , 5 , 7 , 1 };
    int minimum;

    minimum = recursiveMin( val , 0 , SIZE -1 );
    printf( "minimum value = %d" , minimum );

    return 0;
}

int recursiveMin( int a[] , int low , int high )
{
    static int min = 1000;
    if ( a[ low ] < min ){
        min = a[ low ];
    }
    if ( low == high ){
        return min;
    }else{
        return recursiveMin( a , low + 1 , high );
    }


}
