//visualizing recursion
#include <stdio.h>
int factorial( int );

int main( void )
{
    int number = 5;
    printf( "\n\nfactorial(%d) = %d\n\n" , number , factorial( number ) );

    return 0;
}

int factorial( int n )
{
    static int count = 0;
    printf( "call factorial(%d)\t" , n );
    if ( n == 1 ){
        for ( int i = 0; i < count; ++i ){
            printf( "\t" );
        }++count;
        printf( "return %d\n" , n );
        return 1;
    }else{
        for ( int i = 0; i < count; ++i ){
            printf( "\t" );
        }++count;
        printf( "%d * factorial(%d)\n" , n , n - 1 );
        return n * factorial( n - 1);
    }
}
