//demonstrate non-constant pointer to non-constant data
//non constant pointer is needed because it involves pointer arithmetic
//non constant data because the char need to be change if it is a lowercase
#include <stdio.h>
#include <ctype.h>

void convertToUpper( char *sPtr );

int main( void )
{
    char string[] = { "Hello semua, apa khabar?" };
    printf( "string before conversion: %s\n" , string );
    convertToUpper( string );
    printf( "string after conversion: %s\n" , string );

    return 0;
}

void convertToUpper( char *sPtr )
{
    while ( *sPtr != '\0' ){
        if ( islower( *sPtr ) ){
            *sPtr = toupper( *sPtr );
        }
        ++sPtr;
    }

}
