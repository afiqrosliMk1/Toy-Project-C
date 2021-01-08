//non constant pointer to constant data
#include <stdio.h>

void printArray( const char *sPtr );

int main( void )
{
    char string[] = { "This is a string literal" };
    printArray( string );

    return 0;
}

void printArray( const char *sPtr ) //sPtr is a pointer to constant character. sPtr can't be use to change value of data it points
{
    for ( ; *sPtr != '\0'; ++sPtr ){
        printf( "%c" , *sPtr );
    }
}
