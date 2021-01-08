//recursion first example, using factorial
#include <stdio.h>

long factorial( long y );

int main( void )
{
    int number;

    for ( number = 1; number <= 10; number++ ){
        printf( "factorial %d = %ld\n
               " , number , factorial( number ) );
    }

    return 0;
}

long factorial( long y )
{
    if ( y <= 1){
        return 1;
    }else{
        return y * factorial( y - 1 );
    }
}
