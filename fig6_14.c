//compilation error because const array can't be modified
#include <stdio.h>
#define SIZE 3

void tryToModifyArray( const int n[] , int arraySize );

int main( void )
{
    int a[ SIZE ] = { 0 , 1 , 2 };
    tryToModifyArray( a , SIZE );

    return 0;
}

void tryToModifyArray( const int n[] , int arraySize )
{
    int i;
    for ( i = 0; i < arraySize; ++i ){
        n[ i ] += 10;
    }
}
