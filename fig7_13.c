//constant pointer to non-constant data. like array name
//this kind of pointer must be initialized once they are declared
//for pointer that is a function parameter, it is initialized with the pointer that is passed to the function
#include <stdio.h>

int main( void )
{
    int m = 10;
    //int n = 12;

    int *const ptr = &m;
    printf( "*ptr = %d\n" , *ptr );
    *ptr = 30;
    printf( "*ptr = %d\n" , *ptr );

    //ptr = &n; #ERROR

    return 0;
}
