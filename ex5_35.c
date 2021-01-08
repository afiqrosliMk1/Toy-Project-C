//iterative fibonacci
#include <stdio.h>
double fibonacci( int n );

int main( void )
{
    int val = 0 ;
    for ( ; val <= 2000; val++ ){
        printf( "fibonacci(%d) = %lf\n" , val , fibonacci( val ) );
    }

    return 0;
}

double fibonacci( int n )
{
    double n0 = 0 , n1 = 1 , fib = 0;
    int i = 2;

    if ( n == 0 ){
        return 0;
    }else if ( n == 1 ){
        return 1;
    }else{
        while ( i <= n ){
            fib = n1 + n0;
            n0 = n1;
            n1 = fib;
            ++i;
        }//end while
    }

    return fib;
}
