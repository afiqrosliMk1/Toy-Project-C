//paper size 8.5 inch wide. 1 inch margin left right

#define WIDTH 100

#include <stdio.h>
#include <string.h>

void subsituteNull( char *strPtr , char *tailPtr );

int main( void )
{
    char text[ WIDTH ] = { "to be or not to be is not my concern do you understand or not huh?" };
    char *endPtr;
    char *tokenPtr = NULL;
    char *tokenPtrArray[ 20 ] = { 0 };
    int i = 0 , j = 0;
    int shiftAmount = 0;
    int wordCount = 0;

    //printf( "%p" , &text[ 19 ] );
    endPtr = strchr( text , '\0' );

    tokenPtr = strtok( text , " " );
    while ( tokenPtr != NULL ){
        ++wordCount;
        tokenPtrArray[ i++ ] = tokenPtr;
        tokenPtr = strtok( NULL , " " );
    }

    subsituteNull( text , endPtr );

    for ( ; endPtr != &text[ WIDTH - 1 ]; ){
        for ( i = 1; i < wordCount; ++i ){
            shiftAmount = endPtr - tokenPtrArray[ i ] + sizeof( char ); //how many bytes to shift
            memmove( tokenPtrArray[ i ] + 1  , tokenPtrArray[ i ] , shiftAmount ); //move one byte to the right
            memset( tokenPtrArray[ i ] , ' ' , sizeof( char ) ); //set bbe -> ' 'be

            endPtr += 1; //increment value of endPtr after each shift
            if ( endPtr >= &text[ WIDTH - 1 ] ){
                break;
            }
            for ( j = i; j < wordCount; ++j ){
                tokenPtrArray[ j ] += 1; //increment the memory address after each shift
            }

        }
    }
    puts( text );





    return 0;
}

void subsituteNull( char *strPtr , char *tailPtr )
{
    int i = 0;
    for ( i = 0; &strPtr[ i ] != tailPtr; ++i ){
        if ( strPtr[ i ] == '\0' ){
            memset( &strPtr[ i ] , ' ' , 1 );
        }
    }
}

