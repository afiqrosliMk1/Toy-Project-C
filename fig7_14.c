//constant pointer to constant data
#include <stdio.h>

int main( void )
{
    int a = 10;
    int b = 0;
    const int *const ptr = &a;

    *ptr = 2; //ERROR
    ptr = &b;

    return 0;
}
