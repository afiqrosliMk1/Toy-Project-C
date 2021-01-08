//recursive array printing / start from highest index
#include <stdio.h>
#define SIZE 3
void recursiveArrayPrint( int b[] , int startIndex , int arraySize );

int main( void )
{
    int a[ SIZE ] = { 3 , 4 , 8 }; //, 12 , 14 , 15 , 17 , 29 , 30 , 39 };
    recursiveArrayPrint( a , 0 , SIZE );

    return 0;
}

void recursiveArrayPrint( int b[] , int startIndex , int arraySize )
{
    if ( startIndex < arraySize ){
        recursiveArrayPrint( b , startIndex + 1 , SIZE );
        printf( "%d\n" , b[ startIndex ] );
    }
    //automatically return control after startIndex == arraySize
}
