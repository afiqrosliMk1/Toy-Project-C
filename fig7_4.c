#include <stdio.h>

int main( void )
{
    int a = 7;
    int* aPtr = &a;

    printf( "Address of a is %p\n" , &a );
    printf( "Value of aPtr is %p\n" , aPtr );

    printf( "Value of a is %d\n" , a );
    printf( "Value of *aPtr is %d\n" , *aPtr );

    printf( "Value of &*aPtr is %p\n " , &*aPtr );
    printf( "Value of *&aPtr is %p\n" , *&aPtr );

    return 0;
}
