#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToLower( char* text , int n );

int main( void )
{
    char sentences[ 3 ][ 80 ] = { '\0' };
    int letter[ 26 ] = { 0 };
    int wordLength[ 100 ] = { 0 };
    char *tokenPtrArray[ 100 ] = { 0 }; //store the address of tokenized words
    int i , j;
    char *wPtr;
    char *tokenPtr = NULL;
    int word;
    int *letterPtr = letter;

    //input sentences
    printf( "Enter several sentences:\n" );

    for ( i = 0; i < 3; ++i ){
        fgets( sentences[ i ] , 80 , stdin );
    }

    //convert all letters to lowercase
    convertToLower( sentences[ 0 ] , 3 );

    //search for occurrence of each character
    for ( word = 97; word <= 122; ++word , letterPtr++ ){
        for ( i = 0; i < 3; ++i ){
            wPtr = sentences[ i ];
            while ( ( wPtr = strchr( wPtr , word ) ) != NULL ){
                ++wPtr;
                ++( *letterPtr );
            }
        }//end for i
    }//end for word

    //print result showing counts of each letter
    puts( "Table of letter counts:\n" );
    for ( i = 0; i <= 25; ++i ){
        printf( "%3c%4d\n" , 'a' + i , letter[ i ] );
    }

    //tokenize sentence into words and save the pointers returned from strtok() into tokenPtrArray
    i = 0;
    for ( j = 0 ; j < 3; ++j ){
        tokenPtr = strtok( sentences[ j ] , " " );
        while ( tokenPtr != NULL ){
            tokenPtrArray[ i ] = tokenPtr;
            tokenPtr = strtok( NULL , " " );
            ++i;
        }
    }


    //print the string pointed to each element of tokenPtrArray
    /*for ( i = 0; tokenPtrArray[ i ] != NULL; ++i ){
        puts( tokenPtrArray[ i ] );
        //printf( "%p\n" , tokenPtrArray[ i ] );
    }*/

    //=========== search for newline in string saved inside tokenPtrArray and replace with '\0' ==============//
    char *newlinePtr;

    for ( i = 0; tokenPtrArray[ i ] != NULL; ++i ){
        newlinePtr = strchr( tokenPtrArray[ i ] , '\n' );
        if ( newlinePtr != NULL ){
            *newlinePtr = '\0';
        }
    }
    //=======================================================================================================//

    //analyze the length of each element of tokenPtrArray. show how many words are 2 letters, 3 letter , 4 letter , etc..
    for ( i = 0; tokenPtrArray[ i ] != NULL; ++i ){

        ++wordLength[ strlen( tokenPtrArray[ i ] ) ];
    }

    printf( "%-15s%-15s\n" , "Word Length" , "Occurrences" );
    for ( i = 1; i < 10; ++i ){
        printf( "%-15d%-15d\n" , i , wordLength[ i ] );
    }

    //===================end of problem (b)=====================================================//
    //====================start of problem (c)==================================================//
    int wordCount[ 200 ] = { 0 };
    int pass;
    char *temp;

    //sort tokenPtrArray

    for ( pass = 1; pass < 100; ++pass ){
        for ( i = 0; i < 99; ++i ){
            if ( tokenPtrArray[ i ] != NULL && tokenPtrArray[ i + 1 ] != NULL ){
                if ( strcmp( tokenPtrArray[ i ] , tokenPtrArray[ i + 1 ] ) > 0 ){
                    temp = tokenPtrArray[ i ];
                    tokenPtrArray[ i ] = tokenPtrArray[ i + 1 ];
                    tokenPtrArray[ i + 1 ] = temp;
                }
            }
        }
    }
    //end of sorting words

    for ( pass = 0; pass < 100; ++pass ){ //100 is the size of tokenPtrArray
        if ( tokenPtrArray[ pass ] != NULL ){ //increment to 1 if the word is not NULL
            ++wordCount[ pass ];
        }
        for ( i = pass + 1; i < 100; ++i ){
            if ( tokenPtrArray[ pass ] != NULL && tokenPtrArray[ i ] != NULL ){ //make sure both are not NULL before calling strcmp()
                if ( strcmp( tokenPtrArray[ pass ] , tokenPtrArray[ i ] ) == 0 ){
                    tokenPtrArray[ i ] = NULL; //change the comparison value to NULL
                    ++wordCount[ pass ];//increment the counter
                }
            }
        }// end for i
    }//end for pass

    for ( i = 0; i < 100; ++i ){
        if ( tokenPtrArray[ i ] != NULL ){
            printf( "%-5s%5d\n" , tokenPtrArray[ i ] , wordCount[ i ] );
        }
    }printf( "\n" );

    return 0;
}

void convertToLower( char* text , int n )
{
    int i , j;

    for ( i = 0; i < n; ++i , text += 80 ){
        for ( j = 0; j < 80; ++j ){
            text[ j ] = tolower( text[ j ] );
        }
    }
}
