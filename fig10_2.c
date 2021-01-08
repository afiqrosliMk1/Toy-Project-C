#include <stdio.h>

struct card {
    char *face;
    char *suit;
};

int main( void )
{
    struct card aCard; //define one struct card variable
    struct card *cardPtr; //define a pointer to a struct card

    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard; //assign address of aCard to cardPtr

    printf( "%s%s%s\n%s%s%s\n%s%s%s\n" , aCard.face , " of " , aCard.suit ,
           cardPtr->face , " of " , cardPtr->suit ,
           ( *cardPtr ).face , " of " , ( *cardPtr ).suit );

    return 0;
}
