#include <stdio.h>
#include <string.h>

void searchCapital( char *sentencePtr , int *alphaCountPtr );
void printResult( int *alphaCountPtr , int size );

int main( void )
{
    char sentence[ 100 ] = " ";
    int alphaCount[ 26 ] = { 0 };

    puts( "Enter a line of word: " );
    fgets( sentence , 100 , stdin );
    *( strchr( sentence , '\n' ) ) = '\0';

    searchCapital( sentence , alphaCount );
    printResult( alphaCount , 26 );

    return 0;
}

void searchCapital( char *sentencePtr , int *alphaCountPtr )
{
    char searchCharacter;
    char *searchPtr = NULL;
    int count;
    int i = 0;

    //searching for capital letter. 65 is A , 90 is Z
    for ( searchCharacter = 65; searchCharacter <= 90; ++searchCharacter , i++ ){
        count = 0;
        searchPtr = strchr( sentencePtr , searchCharacter );

        if ( searchPtr != NULL ){
            while ( searchPtr != NULL ){
                ++count;
                searchPtr = strchr( searchPtr + 1 , searchCharacter );
            }
            alphaCountPtr[ i ] += count;
        }

    }//end outer if

    //searching for small letter. 97 is a , 122 is z
    for ( searchCharacter = 97 , i = 0; searchCharacter <= 122; ++searchCharacter , i++ ){
        count = 0;
        searchPtr = strchr( sentencePtr , searchCharacter );

        if ( searchPtr != NULL ){
            while ( searchPtr != NULL ){
                ++count;
                searchPtr = strchr( searchPtr + 1 , searchCharacter );
            }
            alphaCountPtr[ i ] += count;
        }

    }//end outer if
}

void printResult( int *alphaCountPtr , int size )
{
    int i;

    puts( "Total counts:\n" );
    for ( i = 97; i <= 122; ++i ){
        printf( "%3c" , i );
    }printf( "\n" );

    for ( i = 0; i < size; ++i ){
        printf( "%3d" , alphaCountPtr[ i ] );
    }printf( "\n" );
}
