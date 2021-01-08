//copying string using array notation and pointer notation
#include <stdio.h>
void copy1( char *const s1 , const char *const s2 );
void copy2( char *s3 , char *s4 );

int main( void )
{
    char string1[ 5 ];
    char *string2 = "Hey!";
    char string3[ 6 ];
    char string4[] = "Good!";

    printf( "Original string\n" );
    printf( "string1 = %s\n" , string1 );
    printf( "string2 = %s\n" , string2 );
    printf( "string3 = %s\n" , string3 );
    printf( "string4 = %s\n" , string4 );

    copy1( string1 , string2 );
    copy2( string3 , string4 );

    printf( "After copy\n" );
    printf( "string1 = %s\n" , string1 );
    printf( "string2 = %s\n" , string2 );
    printf( "string3 = %s\n" , string3 );
    printf( "string4 = %s\n" , string4 );

    return 0;
}

//copy using array notation
void copy1( char *const s1 , const char *const s2 ) //remember: char *const is equivalent to array name
{
    int i;
    for ( i = 0; ( s1[ i ] = s2[ i ] ) != '\0'; ++i ){
        ;
    }
}

//copy using pointer notation
void copy2( char *s3 , char *s4 )
{
    for ( ; ( *s3 = *s4 ) != '\0'; ++s3 , ++s4 ){
        ;
    }
}
