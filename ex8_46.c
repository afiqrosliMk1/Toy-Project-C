#include <stdio.h>
#include <string.h>

int main( void )
{
    char text[ 200 ] = "the man has a daughter with his wife";
    char *keyword[ 4 ] =           { "son" , "daughter" , "wife" , "man" };
    char *genderNeutralWord[ 4 ] = { "child" , "child" , "spouse" , "person" };
    int i;
    char *strPtr = NULL;
    char *fromPtr;
    char *toPtr;
    char temp[ 200 ] = "";
    int shiftAmount;

    printf( "%s\n" , text );

    for ( i = 0; i < 4; ++i ){

        strPtr = strstr( text , keyword[ i ] );

        if ( strPtr != NULL ){ //means a match is found

            if ( strlen( keyword[ i ] ) < strlen( genderNeutralWord[ i ] ) ){//if the original shorter than the gender neutral one, shift

                shiftAmount = strlen( genderNeutralWord[ i ] ) - strlen( keyword[ i ] );
                fromPtr = strPtr + strlen( keyword[ i ] );
                toPtr = fromPtr + shiftAmount;

                memmove( temp , fromPtr , strlen( fromPtr ) + 1 ); //copy to temporary array

                memset( fromPtr , ' ' , shiftAmount ); //set the array to ' ' from "fromPtr" to the right, sebanyak "shiftAmount" bytes

                memmove( toPtr , temp , strlen( temp ) + 1 ); //copy back from temporary array into text starting at tempPtr

                memmove( strPtr , genderNeutralWord[ i ] , strlen( genderNeutralWord[ i ] ) );


            }else{ //if the original word is longer than the "gender neutral" one
                memset( strPtr , ' ' , strlen( keyword[ i ] ) );
                memmove( strPtr , genderNeutralWord[ i ] , strlen( genderNeutralWord[ i ] ) );
            }

        }//end if
    }//end for

    puts( text );

    //=======================eliminate the extra space created===========================//
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


    return 0;
}
