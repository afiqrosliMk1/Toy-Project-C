#include <stdio.h>
#include <stdlib.h>

void shuffleAndDeal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] );

int main( void )
{
    int deck[ 4 ][ 13 ] = { 0 };
    char *suit[ 4 ] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };
    char *face[ 13 ] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
                        "Nine" , "Ten" , "Jack" , "Queen" , "King" };
    shuffleAndDeal( deck , suit , face );

    return 0;
}

void shuffleAndDeal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] )
{
    int card , row , column;

    for ( card = 1; card <= 52; ++card ){
        do{
            row = rand() % 4;
            column = rand() % 13;
        }while( wDeck[ row ][ column ] != 0 );

        wDeck[ row ][ column ] = card;
        printf( "%7s of %-9s%c" , wFace[ column] , wSuit[ row ] ,
                card % 2 == 0 ? '\n' : '\t' );
     }
}
