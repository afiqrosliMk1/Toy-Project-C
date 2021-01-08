#include <stdio.h>
int mystery( int , int );

int main( void )
{
    printf( "%d\n" , mystery( 2 , -9 ) );

    return 0;
}

int mystery( int a , int b )
{
    if ( b == 1 ){
        return a;
    }else if ( b < 0 ){
        a *= -1;
        b *= -1;
        return a + mystery( a , b - 1 );
    }else{
        return a + mystery( a , b - 1 );
    }
}
