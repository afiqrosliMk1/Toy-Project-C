#include <stdio.h>
#include <stdlib.h>
void shuffle( int wDeck[][ 13 ] );
void deal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] );

int main( void )
{
    int deck[ 4 ][ 13 ] = { 0 };
    char *suit[ 4 ] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };
    char *face[ 13 ] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
                        "Nine" , "Ten" , "Jack" , "Queen" , "King" };
    shuffle( deck );
    deal( deck , suit , face );

    return 0;
}

void shuffle( int wDeck[][ 13 ] )
{
    int card , row , column;

    for ( card = 1; card <= 52; ++card ){
        do{
            row = rand() % 4;
            column = rand() % 13;
        }while( wDeck[ row ][ column ] != 0 );

        wDeck[ row ][ column ] = card;
     }
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
