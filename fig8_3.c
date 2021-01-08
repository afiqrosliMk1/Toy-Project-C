#include <stdio.h>
#include <ctype.h>

int main( void )
{
    printf( "According to islower(): \n" );
    printf( "%s %s\n" ,islower( 'A' ) ? "A is a" : "A is not a" , "lowercase letter" );
    printf( "%s %s\n" ,islower( 'f' ) ? "f is a" : "f is not a" , "lowercase letter" );
    printf( "%s %s\n" ,islower( '9' ) ? "9 is a" : "9 is not a" , "lowercase letter" );
    printf( "%s %s\n" ,islower( '*' ) ? "* is a" : "* is not a" , "lowercase letter" );

    printf( "\nAccording to isupper(): \n" );
    printf( "%s %s\n" ,isupper( 'A' ) ? "A is an" : "A is not a" , "uppercase letter" );
    printf( "%s %s\n" ,isupper( 'f' ) ? "f is an" : "f is not a" , "uppercase letter" );
    printf( "%s %s\n" ,isupper( '9' ) ? "9 is an" : "9 is not a" , "uppercase letter" );
    printf( "%s %s\n" ,isupper( '*' ) ? "* is an" : "* is not a" , "uppercase letter" );

    printf( "\n" );
    printf( "b converted to uppercase is %c\n" , toupper( 'b' ) );
    printf( "6 converted to uppercase is %c\n" , toupper( '6' ) );
    printf( "! converted to uppercase is %c\n" , toupper( '!' ) );

    printf( "\n" );
    printf( "Y converted to lowercase is %c\n" , tolower( 'Y' ) );
    printf( "6 converted to lowercase is %c\n" , tolower( '6' ) );
    printf( "%% converted to lowercase is %c\n" , tolower( '%' ) );


    return 0;
}
