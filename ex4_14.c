#include <stdio.h>

int main( void )
{
    int i , n = 1;
    unsigned factorial;

    for ( n = 1; n <= 19; n++ ){
        factorial = 1;
        for ( i = 1; i <= n; i++ ){
        factorial *= i;
        }
        printf( "%d! = %d\n" , n , factorial );
    }

    return 0;
}
