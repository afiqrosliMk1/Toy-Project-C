//modification of shuffling and dealing to avoid indefinite postponement
#include <stdio.h>
#include <stdlib.h>
void shuffle( int wDeck[][ 13 ] );
void deal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] );
void showDeck( int wDeck[][ 13 ] );

int main( void )
{
    int deck[ 4 ][ 13 ] = { { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 } ,
                            { 14 , 15 , 16 , 17 , 18 , 19 , 20 , 21 , 22 , 23 , 24 , 25 , 26 } ,
                            { 27 , 28 , 29 , 30 , 31 , 32 , 33 , 34 , 35 , 36 , 37 , 38 , 39 } ,
                            { 40 , 41 , 42 , 43 , 44 , 45 , 46 , 47 , 48 , 49 , 50 , 51 , 52 } };
    char *suit[ 4 ] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };
    char *face[ 13 ] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
                        "Nine" , "Ten" , "Jack" , "Queen" , "King" };

    showDeck( deck );
    shuffle( deck );
    showDeck( deck ); //is not a dealing function, just to peep into the deck to see how good the shuffling is
    shuffle( deck );
    deal( deck , suit , face );

    return 0;
}

void shuffle( int wDeck[][ 13 ] )
{
    int hold , row , column;
    int randomRow , randomColumn;

    for ( row = 0; row <= 3; ++row ){
        for ( column = 0; column <= 12; ++column ){
            randomRow = rand() % 4;
            randomColumn = rand() % 13;

            hold = wDeck[ row ][ column ];
            wDeck[ row ][ column ] = wDeck[ randomRow ][ randomColumn ];
            wDeck[ randomRow ][ randomColumn ] = hold;
        }//end for column
    }//end for column
}

void deal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] )
{
    int card , row , column;

    for ( card = 1; card <= 52; ++card ){
        for ( row = 0; row <= 3; ++row ){
            for ( column = 0; column <= 12; ++column ){
                if ( wDeck[ row ][ column ] == card ){
                    printf( "%7s of %-9s%c" , wFace[ column] , wSuit[ row ] ,
                           card % 2 == 0 ? '\n' : '\t' );
                }
            }
        }
    }

}

void showDeck( int wDeck[][ 13 ] )
{
    int row , column;

    for ( row = 0; row <= 3; ++row ){
        for ( column = 0; column <= 12; ++column ){
            printf( "%3d" , wDeck[ row ][ column ] );
        }printf( "\n" );
    }printf( "\n" );
}
