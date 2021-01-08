#include <stdio.h>

int maximum( int i , int j , int k );

int main( void )
{
    int x , y , z;

    printf( "Enter 3 integers to determine the maximum: " );
    scanf( "%d%d%d" , &x , &y ,&z );

    printf( "Max: %d" , maximum( x , y , z ) );

    return 0;
}

int maximum( int i , int j , int k )
{
    int max = i;
    if ( j > max ){
        max = j;
    }
    if ( k > max ){
        max = k;
    }
    return max;
}
