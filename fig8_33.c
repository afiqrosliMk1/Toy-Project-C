#include <stdio.h>
#include <string.h>

int main( void )
{
    char s1[] = "ABCDEFG";
    char s2[] = "ABCHIJK";

    printf( "s1 = %s\ns2 = %s\n" , s1 , s2 );

    printf( "memcmp( s1 , s2 , 3 ) = %d\n" , memcmp( s1 , s2 , 3 ) );
    printf( "memcmp( s1 , s2 , 5 ) = %d\n" , memcmp( s1 , s2 , 5 ) );
    printf( "memcmp( s2 , s1 , 5 ) = %d\n" , memcmp( s2 , s1 , 5 ) );

    return 0;
}
