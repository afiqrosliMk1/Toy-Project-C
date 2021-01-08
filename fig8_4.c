//character handling library
#include <stdio.h>
#include <ctype.h>

int main( void )
{
    printf( "According to isspace():\n" );
    printf( "%s %s\n" , "Space" , isspace( ' ' ) ? "is whitespace character" : "is not a whitespace character" );
    printf( "%s %s\n" , "Horizontal Tab" , isspace( '\t' ) ? "is whitespace character" : "is not a whitespace character" );
    printf( "%s %s\n" , "Vertical Tab" , isspace( '\v' ) ? "is whitespace character" : "is not a whitespace character" );
    printf( "%s %s\n" , "Carriage Return" , isspace( '\r' ) ? "is whitespace character" : "is not a whitespace character" );
    printf( "%s %s\n" , "Alert" , isspace( '\a' ) ? "is whitespace character" : "is not a whitespace character" );

    printf( "\nAccording to iscntrl():\n" );
    printf( "%s %s\n" , "Newline" , iscntrl( '\n' ) ? "is control character" : "is not a control character" );
    printf( "%s %s\n" , "Horizontal Tab" , iscntrl( '\t' ) ? "is control character" : "is not a control character" );
    printf( "%s %s\n" , "Backspace" , iscntrl( '\b' ) ? "is control character" : "is not a control character" );
    printf( "%s %s\n" , "Carriage Return" , iscntrl( '\r' ) ? "is control character" : "is not a control character" );
    printf( "%s %s\n" , "Alert" , iscntrl( '\a' ) ? "is control character" : "is not a control character" );

    printf( "\nAccording to ispunct():\n" );
    printf( "%s %s\n" , "Newline" , ispunct( '\n' ) ? "is punctuation character" : "is not a punctuation character" );
    printf( "%s %s\n" , "Horizontal Tab" , ispunct( '\t' ) ? "is punctuation character" : "is not a punctuation character" );
    printf( "%s %s\n" , "Space" , ispunct( ' ' ) ? "is punctuation character" : "is not a punctuation character" );
    printf( "%s %s\n" , "M" , ispunct( 'M' ) ? "is punctuation character" : "is not a punctuation character" );
    printf( "%s %s\n" , "!" , ispunct( '!' ) ? "is punctuation character" : "is not a punctuation character" );

    printf( "\nAccording to isprint():\n" );
    printf( "%s %s\n" , "Newline" , ispunct( '\n' ) ? "is printing character" : "is not a printing character" );
    printf( "%s %s\n" , "Horizontal Tab" , ispunct( '\t' ) ? "is printing character" : "is not a printing character" );
    printf( "%s %s\n" , "Space" , ispunct( ' ' ) ? "is printing character" : "is not a printing character" );
    printf( "%s %s\n" , "M" , ispunct( 'M' ) ? "is printing character" : "is not a printing character" );
    printf( "%s %s\n" , "!" , ispunct( '!' ) ? "is printing character" : "is not a printing character" );

    printf( "\nAccording to isgraph():\n" );
    printf( "%s %s\n" , "Newline" , isgraph( '\n' ) ? "is printing character other than space" : "is not a printing character other than space" );
    printf( "%s %s\n" , "Alert" , isgraph( '\a' ) ? "is printing character other than space" : "is not a printing character other than space" );
    printf( "%s %s\n" , "Space" , isgraph( ' ' ) ? "is printing character other than space" : "is not a printing character other than space" );
    printf( "%s %s\n" , "." , isgraph( '.' ) ? "is printing character other than space" : "is not a printing character other than space" );
    printf( "%s %s\n" , "#" , isgraph( '#' ) ? "is printing character other than space" : "is not a printing character other than space" );
    return 0;
}
