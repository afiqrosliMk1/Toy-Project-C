//demonstrate scope rules
#include <stdio.h>

void useLocal( void );
void useStaticLocal( void );
void useGlobal( void );

int x = 5; //global variables will be storage class extern (static storage duration)

int main( void )
{
    int x = 3;
    {
        int x = 8;
        printf( "x in main (inside block): %d\n" , x );
    }
    printf( "x in \"main\" block: %d\n\n" , x );

    useLocal();
    useStaticLocal();
    useGlobal();
    printf( "\n\n" );
    useLocal();
    useStaticLocal();
    useGlobal();

    printf( "x in \"main\" block: %d" , x );
    return 0;
}

void useLocal( void )
{
    int x = 77;
    printf( "x in useLocal(initial) : %d\n" , x );
    x++;
    printf( "x in useLocal (after increment): %d\n" , x );
}

void useStaticLocal( void )
{
    static int x = 91;
    printf( "x in useLocal(initial) : %d\n" , x );
    x++;
    printf( "x in useLocal (after increment): %d\n" , x );
}

void useGlobal( void )
{
    printf( "x in global (initial): %d\n" , x );
    x++;
    printf( "x in global (after increment): %d\n\n" , x );
}
