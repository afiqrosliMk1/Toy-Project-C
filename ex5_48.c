//recursive fibonacci variant - tail recursion
#include <stdio.h>
int fibonacciTR( int , int , int );

int main( void )
{
    int term = 5;
    printf( "fibonacci(%d) = %d" , term , fibonacciTR( term , 0 , 1 ) ); //only in c++ you can supply default argument

    return 0;
}

int fibonacciTR( int n , int a , int b )
{
    if ( n == 0 ){
        return a;
    }else if ( n == 1 ){
        return b;
    }else{
        return fibonacciTR( n - 1 , b , b + a ); //simply give value b to 'a' and b + a to 'b' in the header
    }
}

