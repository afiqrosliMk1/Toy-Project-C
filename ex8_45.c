#include <stdio.h>
#include <string.h>

int main( void )
{
    char text[] = "hey i got to go now, if you don't mind , i don't know";
    char text2[ 100 ] = "hey fyi, nothing just gtg where idk";
    int i = 0;
    char *keyWord[ 3 ] = { "got to go" , "i don't know" , "for your information" };
    char *smsWord[] = { "gtg" , "idk" , "fyi" };
    char *strPtr = NULL;


    //===========================================================================================//
    //translating from English to sms language
    //===========================================================================================//
    for ( i = 0; i < 3; ++i ){
        strPtr = strstr( text , keyWord[ i ] );
        if ( strPtr != NULL ){
            memset( strPtr , ' ' , strlen( keyWord[ i ] ) ); //set n element (depends on keyword) to whitespace
            memmove( strPtr , smsWord[ i ] , strlen( smsWord[ i ] ) );
        }
    }



    //make the words nearer to each other, eliminate extra whitespace
    int whitespCount = 0;

    for ( i = 0; text[ i ] != '\0'; ++i ){
        if ( text[ i ] == ' ' ){
            ++whitespCount;
        }else{
            whitespCount = 0;
        }

        if ( whitespCount > 1 ){
            memmove( &text[ i ] - 1 , &text[ i ] , strlen( &text[ i ] ) + 1 ); //plus one, to include '\0'

            whitespCount = 0; //reset white space count back to zero once text is shifted
            i = 0; //start the process over again
        }
    }

    puts( text );

    //===================================================================================================//
    //translating from SMS language to English
    //===================================================================================================//
    int shiftAmount = 0;
    char *fromPtr;
    char *toPtr;
    char temp[ 100 ] = "";

    for ( i = 0; i < 3; ++i ){
        strPtr = strstr( text2 , smsWord[ i ] );
        if ( strPtr != NULL ){ //if there is a match

            shiftAmount = strlen( keyWord[ i ] ) - strlen( smsWord[ i ] );
            fromPtr = strPtr + strlen( smsWord[ i ] );
            toPtr = fromPtr + shiftAmount;

            memmove( temp , fromPtr , strlen( fromPtr ) + 1 ); //shift string to the right, starting at ',' sebanyak strlen( strPtr ) + 1
            //set the from "fromPtr" in text2 to ' '
            memset( fromPtr , ' ' , shiftAmount );
            //copy from temp to text2
            memmove( toPtr , temp , strlen( temp ) + 1 );
            //puts( "text2 is: " ); puts( text2 );
            //change sms language to english
            memmove( strPtr , keyWord[ i ] , strlen( keyWord[ i ]) );
            puts( text2 );
        }
    }


    return 0;
}
