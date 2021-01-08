#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main( void )
{
    char *morseLetter[] = { ".-" , "-..." , "-.-." , "-.." , "." , "..-." , "--." , "...." , ".." , ".---" , "-.-" , ".-.." , "--" ,
                        "-." , "---" , ".--." , "--.-" , ".-." , "..." , "-", "..-" , "...-" , ".--" , "-..-" , "-.--" , "--.." };
    char *morseDigit[] = { "-----" , ".----" , "..---" , "...--" , "....-" , "....." , "-...." , "--..." , "---.." , "----." };
    char text[] = "Hello 01!";
    char code[] = ".-   ..-.   ..   --.-";
    int i = 0;
    char *tokenPtr;

    //convert into lowercase
    for ( i = 0; text[ i ] != '\0'; ++i ){
        text[ i ] = tolower( text[ i ] );
    }

    for ( i = 0; text[ i ] != '\0'; ++i ){
        if ( text[ i ] == ' ' ){
            printf( "   " ); //print three spaces between words
        }else if ( isdigit( text[ i ] ) ){
            printf( "%s " , morseDigit[ text[ i ] - 48 ] );
        }else if ( isalpha( text[ i ] ) ){
            printf( "%s " , morseLetter[ text[ i ] - 97 ] );
        }else{
            putchar( text[ i ] );
        }
    }

    tokenPtr = strtok( code , " " );
    while ( tokenPtr != NULL ){
        for ( i = 0; i <= 25; ++i ){
            if ( strcmp( tokenPtr , morseLetter[ i ] ) == 0 ){
                printf( "%c" , 'a' + i );
            }
        }
        for ( i = 0; i <= 9; ++i ){
            if ( strcmp( tokenPtr , morseDigit[ i ] ) == 0 ){
                printf( "%c" , '0' + i );
            }
        }

        tokenPtr = strtok( NULL , " " );
    }

    return 0;
}
