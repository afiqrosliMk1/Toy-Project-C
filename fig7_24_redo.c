#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void deal( const int wDeck[][ 13 ] , const char* wFace[] , const char* wSuit[] );
void shuffle( int wDeck[][ 13 ] );

int main( void )
{
    //initialize suit array
    const char *suit[ 4 ] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };

    //initialize face array
    const char *face[ 13 ] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
        "Nine" , "Ten" , "Jack" , "Queen" , "King" };

    //initialize deck array
    int deck[ 4 ][ 13 ] = { 0 };

    srand( time( NULL ) );

    shuffle( deck );
    deal( deck , face , suit );

    return 0;
}

void shuffle( int wDeck[][ 13 ] )
{
    int card;
    int wRow;
    int wColumn;

    for ( card = 1; card <= 52; ++card ){
        wRow = rand() % 4;
        wColumn = rand() % 13;

        while ( wDeck[ wRow ][ wColumn ] != 0 ){
            wRow = rand() % 4;
            wColumn = rand() % 13;
        }

        wDeck[ wRow ][ wColumn ] = card;
    }
}

void deal( const int wDeck[][ 13 ] , const char* wFace[] , const char* wSuit[] )
{
    int card;
    int wRow , wColumn;

    for ( card = 0; card <= 52; ++card ){
        for ( wRow = 0; wRow < 4; ++wRow ){
            for ( wColumn = 0; wColumn < 13; ++wColumn ){
                if ( wDeck[ wRow ][ wColumn ] == card ){
                    printf( "%fts of %s\n" , wFace[ wColumn ] , wSuit[ wRow ] );
                }
            }
        }
    }
}
