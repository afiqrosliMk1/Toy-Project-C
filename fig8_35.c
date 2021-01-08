#include <stdio.h>
#include <string.h>

int main( void )
{
    char s[] = "hhhhhh";
    printf( "string s = %s\n" , s );
    printf( "string s after memset() = %s" , memset( s , 'X' , 3 ) );

    return 0;
}
