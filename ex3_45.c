#include <stdio.h>

int main( void )
{
    int a , b , c;
    printf( "Input 3 sides to determine whether they can represent right angled triangle: " );
    scanf( "%d%d%d" , &a , &b , &c );

    if ( a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a ){
        printf( "yes it can" );
    }else{
        printf( "no it can't" );
    }

    return 0;
}
