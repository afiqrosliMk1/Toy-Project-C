//demonstrating the relationship array-pointer
//using 4 methods to refer an array
//pointer + offset (pointer as pointer) , pointer + offset (array name as pointer)
//pointer subsripting eg: bPtr[ 3 ]
//array subscripting ( the most common ) eg: array[ 4 ]
#include <stdio.h>

int main( void )
{
    int a[ 4 ] = { 5 , 3 , 2 , 8 };
    int *aPtr = a;

    printf( "a[3] = %d\n" , a[ 3 ] );
    printf( "aPtr[3] = %d\n" , aPtr[ 3 ] );
    printf( "*( aPtr + 3 ) = %d\n" , *( aPtr + 3 ) );
    printf( "*( a + 3 ) = %d\n" , *( a + 3 ) );


    return 0;
}
