#include <stdio.h>
#include <ctype.h>

int main( void )
{
    printf( "According to isdigit():\n" );
    printf( "%s %s\n" , "8" , isdigit( '8' ) ? "is a digit" : "is not a digit" );
    printf( "%s %s\n" , "#" , isdigit( '#' ) ? "is a digit" : "is not a digit" );
    printf( "%s %s\n" , "A" , isdigit( 'A' ) ? "is a digit" : "is not a digit" );

    printf( "\nAccording to isalpha():\n" );
    printf( "%s %s\n" , "8" , isalpha( '8' ) ? "is a letter" : "is not a letter" );
    printf( "%s %s\n" , "#" , isalpha( '#' ) ? "is a letter" : "is not a letter" );
    printf( "%s %s\n" , "A" , isalpha( 'A' ) ? "is a letter" : "is not a letter" );

    printf( "\nAccording to isalnum():\n" );
    printf( "%s %s\n" , "8" , isalnum( '8' ) ? "is a letter or number" : "is not a letter or number" );
    printf( "%s %s\n" , "#" , isalnum( '#' ) ? "is a letter or number" : "is not a letter or number" );
    printf( "%s %s\n" , "A" , isalnum( 'A' ) ? "is a letter or number" : "is not a letter or number" );

    printf( "\nAccording to isxdigit():\n" );
    printf( "%s %s\n" , "8" , isxdigit( '8' ) ? "is a hexadecimal digit" : "is not a hexadecimal digit" );
    printf( "%s %s\n" , "9" , isxdigit( 'F' ) ? "is a hexadecimal digit" : "is not a hexadecimal digit" );
    printf( "%s %s\n" , "A" , isxdigit( 'A' ) ? "is a hexadecimal digit" : "is not a hexadecimal digit" );
    printf( "%s %s\n" , "a" , isxdigit( 'a' ) ? "is a hexadecimal digit" : "is not a hexadecimal digit" );
    printf( "%s %s\n" , "G" , isxdigit( 'G' ) ? "is a hexadecimal digit" : "is not a hexadecimal digit" );
    return 0;
}
