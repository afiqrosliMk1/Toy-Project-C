#include <stdio.h>
#include <ctype.h>

void printResult( int k );

int main( void )
{
    char c;

    puts( "Enter a character ( -1 to End ): " );
    c = getchar();
    fflush( stdin );

    while( c != EOF ){ //ctrl + z to end
        if( c >= 0 && c <= 255 ){
            printResult( c );
        }else{
            puts( "Invalid value\n" );
        }
        puts( "Enter a character ( -1 to End ): " );
        c = getchar();
        fflush( stdin );
    }

    return 0;
}

void printResult( int k )
{
    printf( "isdigit( %c ) = %d\n" , k , isdigit( k ) );
    printf( "isalpha( %c ) = %d\n" , k , isalpha( k ) );
    printf( "isalnum( %c ) = %d\n" , k , isalnum( k ) );
    printf( "isxdigit( %c ) = %d\n" , k , isxdigit( k ) );

    printf( "islower( %c ) = %d\n" , k , islower( k ) );
    printf( "isupper( %c ) = %d\n" , k , isupper( k ) );
    printf( "tolower( %c ) = %d\n" , k , tolower( k ) );
    printf( "toupper( %c ) = %d\n" , k , toupper( k ) );
    printf( "isspace( %c ) = %d\n" , k , isspace( k ) );

    printf( "iscntrl( %c ) = %d\n" , k , iscntrl( k ) );
    printf( "ispunct( %c ) = %d\n" , k , ispunct( k ) );
    printf( "isprint( %c ) = %d\n" , k , isprint( k ) );
    printf( "isgraph( %c ) = %d\n" , k , isgraph( k ) );

}
