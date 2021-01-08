#include <stdio.h>
#include <string.h>

int main( void )
{
    char x[] = "How are you?";
    char y[ 30 ];
    char z[ 30 ];

    printf( "string x : %s\nstring y : %s\n" , x , strcpy( y , x ) );

    strncpy( z , x , 6 );
    z[ 6 ] = '\0';
    printf( "string z : %s\n" , z );

    return 0;
}
