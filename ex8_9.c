#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( void )
{
    char s1[ 20 ];
    char s2[ 20 ];

    printf( "Enter first string: " );
    fgets( s1 , 20 , stdin );

    printf( "Enter second string: " );
    fgets( s2 , 20 , stdin );

    printf( "s1 = %ss2 = %s\n" , s1 , s2 );

    if ( strcmp( s1 , s2 ) > 0 ){
        printf( "%d\n" , strcmp( s1 , s2 ) );
        printf( "s1 is greater than s2\n" );
    }else if ( strcmp( s1 , s2 ) == 0 ){
        printf( "s1 is equal to s2\n" );
    }else{
        printf( "s2 is greater than s1" );
    }

    return 0;
}
