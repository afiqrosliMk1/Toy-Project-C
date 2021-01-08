#include <stdio.h>
#include <stdlib.h>

struct bitCard{
    unsigned face : 4;
    unsigned suit : 2;
    unsigned color : 1;
};

typedef struct bitCard Card;

void fillDeck( Card *const wDeck );
void shuffle( Card *const wDeck );
void deal( const Card * const wDeck );

int main( void )
{
    Card deck[ 52 ];

    fillDeck( deck );
    shuffle( deck );
    deal( deck );
    return 0;
}

void fillDeck( Card *const wDeck )
{
    int i;

    for ( i = 0; i < 52; ++i ){
        wDeck[ i ].face = i % 13;
        wDeck[ i ].suit = i / 13;
        wDeck[ i ].color = i / 26;
    }
}

void shuffle( Card *const wDeck )
{
    Card temp;
    int i , j;

    for ( i = 0; i < 52; ++i ){
        j = rand() % 52;
        temp = wDeck[ i ];
        wDeck[ i ] = wDeck[ j ];
        wDeck[ j ] = temp;
    }
}

void deal( const Card *const wDeck )
{
    int k1 , k2;
    const char *face[] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" ,
                        "Six" , "Seven" , "Eight" , "Nine" , "Ten" ,
                        "Jack" , "Queen" , "King" };
    const char *suit[] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };
    const char *color[] = { "Red" , "Black" };

    for ( k1 = 0 , k2 = k1 + 26; k1 <= 25; ++k1 , ++k2 ){
        printf( "%s %s of %s   " ,
                 color[ wDeck[ k1 ].color ] , face[ wDeck[ k1 ].face ] ,suit[ wDeck[ k1 ].suit ] );
        printf( "%-s %-s of %-s\n",
               color[ wDeck[ k2 ].color ] , face[ wDeck[ k2 ].face ] , suit[ wDeck[ k2 ].suit ] );
    }
}
