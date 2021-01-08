#include <stdio.h>
#include <string.h>

int main( void )
{
    char s1[ 20 ] = "Selamat ";
    char s2[] = "Hari Raya ";
    char s3[] = "Puasa ";

    printf( "s1 = %s\ns2 = %s\n" , s1 , s2 );
    printf( "strcat( s1 , s2 ) = %s\n" , strcat( s1 , s2 ) );

    printf( "s3 = %s\n" , s3 );
    printf( "strncat( s1 , s3 , 5 ) = %s\n" , strncat( s1 , s3 , 5 ) );

    return 0;
}
