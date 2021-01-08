#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main( void )
{
    char sentence[ 1000 ] = "";
    char *article[] = { "the" , "a" , "one" , "some" , "any" };
    char *noun[] = { "boy" , "girl" , "dog" , "town" , "car" };
    char *verb[] = { "drove" , "jumped" , "ran" , "walked" , "skipped" };
    char *preposition[] = { "to" , "from" , "over" , "under" , "on" };
    int n;
    int turn;
    int word;
    int sentenceCount;

    for ( sentenceCount = 1; sentenceCount <= 20; ++sentenceCount ){
        for ( word = 0; word <= 5; ++word ){
            turn = word % 4;
            n = rand() % 5;

            switch ( turn ){
                case 0:
                    strcat( sentence , article[ n ] );
                    strcat( sentence , " " );
                    break;

                case 1:
                    strcat( sentence , noun[ n ] );
                    if ( word == 5 ){
                        strcat( sentence , "." );
                    }else{
                        strcat( sentence , " " );
                    }
                    break;

                case 2:
                    strcat( sentence , verb[ n ] );
                    strcat( sentence , " " );
                    break;

                case 3:
                    strcat( sentence , preposition[ n ] );
                    strcat( sentence , " " );
                    break;
            }//end switch turn
        }//end for i
        putchar( toupper( sentence[ 0 ] ) );
        printf( "%s\n" , &sentence[ 1 ] );
        sentence[ 0 ] = '\0';

    }


    return 0;
}
