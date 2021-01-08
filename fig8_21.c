//string comparison function
#include <stdio.h>
#include <string.h>

int main( void )
{
    char s1[] = "Afiq";
    char s2[] = "Muhammad";
    char s3[] = "Rosli";
    char s4[] = "Muhammad Afiq";

    printf( "s1 = %s\ns2 = %s\ns3 = %s\n" , s1 , s2 , s3 );

    printf( "strcmp( s1 , s2 ) = %d\n" , strcmp( s1 , s2 ) );
    printf( "strcmp( s2 , s1 ) = %d\n" , strcmp( s2 , s1 ) );
    printf( "strcmp( s3 , s2 ) = %d\n" , strcmp( s3 , s2 ) );
    printf( "strcmp( s2 , s4 ) = %d\n" , strcmp( s2 , s4 ) );

    printf( "\n" );
    printf( "strncmp( s2 , s4 , 8 ) = %d\n" , strncmp( s2 , s4 , 8 ) );


    return 0;
}
