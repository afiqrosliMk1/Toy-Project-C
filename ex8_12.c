#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int main( void )
{
    char sentence[ 1000 ] = "";
    char *article[] = { "the" , "a" , "one" , "some" , "any" };
    char *noun[] = { "boy" , "toy" , "cat" , "mat" , "hat" };
    char *verb[] = { "drove" , "jumped" , "ran" , "walked" , "skipped" };
    char *preposition[] = { "to" , "from" , "over" , "under" , "on" };
    int n;
    int turn;
    int word;
    int sentenceCount;
    char firstRhyme;
    char secondRhyme;

    int getRhyme( char *sPtr );
    srand( time( NULL ) );

    for ( sentenceCount = 0; sentenceCount < 5; ++sentenceCount ){
        for ( word = 0; word <= 5; ++word ){
            turn = word % 4;
            n = rand() % 5;

            switch ( turn ){
                case 0:
                    strcat( sentence , article[ n ] );
                    strcat( sentence , " " );
                    break;

                case 1:
                    if ( word == 5 ){
                        if ( sentenceCount == 1 || sentenceCount == 4 ){
                            while ( getRhyme( noun[ n ] ) != firstRhyme ){
                                n = rand() % 5;
                            }
                            strcat( sentence , noun[ n ] );

                        }else if ( sentenceCount == 3 ){
                            while ( getRhyme( noun[ n ] ) != secondRhyme ){
                                n = rand() % 5;
                            }
                            strcat( sentence , noun[ n ] );

                        }else{ //for sentenceCount = 2 and 0
                            strcat( sentence , noun[ n ] );
                        }strcat( sentence , "." );

                    }else{
                        strcat( sentence , noun[ n ] );
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
        if ( sentenceCount == 0 ){
            firstRhyme = getRhyme( sentence );
        }else if ( sentenceCount == 2 ){
            secondRhyme = getRhyme( sentence );
        }

        putchar( toupper( sentence[ 0 ] ) );
        printf( "%s\n" , &sentence[ 1 ] );
        sentence[ 0 ] = '\0';
        printf( "firstRhyme: %c\n" , firstRhyme );
        printf( "secondRhyme: %c\n" , secondRhyme );
    }

    return 0;
}

int getRhyme( char *sPtr )
{
    while ( *sPtr != '\0' && *sPtr != '.' ){
        ++sPtr;
    }
    return *( --sPtr );
}
