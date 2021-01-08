#include <stdio.h>
#include <string.h>

int main( void )
{
    char text2[ 100 ] = "hey fyi, nothing";
    int i = 0;
    char *keyWord[ 3 ] = { "got to go" , "i don't know" , "for your information" };
    char *smsWord[] = { "gtg" , "idk" , "fyi" };
    char *strPtr = NULL;


    //translating from SMS language to English
    int shiftAmount = 0;
    char *srcPtr = NULL;
    char *destPtr = NULL;

    for ( i = 0; i < 3; ++i ){
        strPtr = strstr( text2 , smsWord[ i ] );
        if ( strPtr != NULL ){ //if there is a match

            shiftAmount = strlen( keyWord[ i ] ) - strlen( smsWord[ i ] );
            srcPtr = strPtr + strlen( smsWord[ i ] );
            destPtr = strPtr + strlen( smsWord[ i ] ) + shiftAmount;

            memmove( destPtr , srcPtr , strlen( strPtr ) + 1 ); //shift string to the right, starting at ',' sebanyak
        }
    }



    puts( text2 );




    return 0;
}

