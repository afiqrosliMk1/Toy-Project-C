#include <stdio.h>

int main( void )
{
    int x = 4;
    int *xPtr = &x;

    printf( "%%d = %d\n" , xPtr );
    printf( "%%lf = %lf\n" , xPtr );
    printf( "%%o = %o\n" , xPtr );
    printf( "%%u = %u\n" , xPtr );
    printf( "%%x = %x\n" , xPtr );
    printf( "%%c = %c\n" , xPtr );
    printf( "%%s = %s\n" , xPtr );
    printf( "%%p = %p\n" , xPtr );


    return 0;
}
