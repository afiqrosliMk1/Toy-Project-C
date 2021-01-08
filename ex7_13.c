#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle( int wDeck[][ 13 ] );
void deal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] , int wHand[][ 5 ] );
int isPair( int wHand[ 5 ] );
int isTwoPair( int wHand[ 5 ] );
int isThreeOfaKind( int c[ 5 ] );
int isFourOfaKind( int c[ 5 ] );
int isFlush( int wHand[ 5 ] );
int isStraight( const int wHand[ 5 ] );
int getColumn( int card , const int wDeck[][ 13 ] );
void printHand( int wHand[][ 5 ] );
void bubbleSort( int array[] , int size );

int main( void )
{
    int deck[ 4 ][ 13 ] = { 0 };
    char *suit[ 4 ] = { "Hearts" , "Diamonds" , "Clubs" , "Spades" };
    char *face[ 13 ] = { "Ace" , "Deuce" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" ,
                        "Nine" , "Ten" , "Jack" , "Queen" , "King" };
    int hand[ 2 ][ 5 ] = { 0 }; //first row: face of the card ( eg: column of card 1 , column of card 2 ... ) , 2nd row suit of cards
    int hand2[ 2 ][ 5 ] = { 0 };
    int rank1 , rank2;

    srand( time( NULL ) );
    shuffle( deck );
    deal( deck , suit , face , hand );
    printf( "\nHand 1:\n" );
    printHand( hand );
    deal( deck , suit , face , hand2 );
    printf( "\nHand 2:\n" );
    printHand( hand2 );

    //evaluate hand 1
    if ( isStraight( hand[ 0 ] ) ){
        printf( "Straight\n" );
        rank1 = 6;
    }else if ( isFlush( hand[ 1 ] ) ){
        printf( "Flush\n" );
        rank1 = 5;
    }else if ( isThreeOfaKind( hand[ 0 ] ) ){
        printf( "Three of a kind\n" );
        rank1 = 4;
    }else if ( isFourOfaKind( hand[ 0 ] ) ){
        printf( "Four of a kind\n" );
        rank1 = 3;
    }else if ( isTwoPair( hand[ 0 ] ) ){
        printf( "Two pairs\n" );
        rank1 = 2;
    }else if ( isPair( hand[ 0 ] ) ){
        printf( "One of a pair\n" );
        rank1 = 1;
    }else{
        rank1 = 0;
    }
    //evaluate hand 2
    if ( isStraight( hand2[ 0 ] ) ){
        printf( "Straight\n" );
        rank2 = 6;
    }else if ( isFlush( hand2[ 1 ] ) ){
        printf( "Flush\n" );
        rank2 = 5;
    }else if ( isThreeOfaKind( hand2[ 0 ] ) ){
        printf( "Three of a kind\n" );
        rank2 = 4;
    }else if ( isFourOfaKind( hand2[ 0 ] ) ){
        printf( "Four of a kind\n" );
        rank2 = 3;
    }else if ( isTwoPair( hand2[ 0 ] ) ){
        printf( "Two pairs\n" );
        rank2 = 2;
    }else if ( isPair( hand2[ 0 ] ) ){
        printf( "One of a pair\n" );
        rank2 = 1;
    }else{
        rank2 = 0;
    }

    //compare which one is better hand
    if ( rank1 > rank2 ){
        printf( "Hand1 wins\n" );
    }else if ( rank1 < rank2 ){
        printf( "Hand2 wins\n" );
    }else{
        printf( "Tie\n" );
    }



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

void deal( int wDeck[][ 13 ] , char *wSuit[] , char *wFace[] , int wHand[][ 5 ] )
{
    int card , row , column;
    static int currentCard = 1;
    int *handPtrFace = &wHand[ 0 ][ 0 ];
    int *handPtrSuit = &wHand[ 1 ][ 0 ];

    for ( card = currentCard; card <= currentCard + 4; ++card ){
        for ( row = 0; row <= 3; ++row ){
            for ( column = 0; column <= 12; ++column ){
                if ( wDeck[ row ][ column ] == card ){
                    printf( "%7s of %-9s\n" , wFace[ column] , wSuit[ row ] );
                    *handPtrFace = column;
                    *handPtrSuit = row;
                    ++handPtrFace;
                    ++handPtrSuit;
                    //wHand[ 0 ][ card - 1 ] = column; //assign face //here is the problem. for hand 2: card - 1 = 5; it should be 0
                    //wHand[ 1 ][ card - 1 ] = row; //assign suit
                }
            }
        }
    }
    currentCard += 5;
    //printf( "Current card = %d\n" , currentCard );
}

int isPair( int wHand[ 5 ] )
{
    int c1 , c2 , c3 , c4 , c5; //means column for card 1 , column for card 2 ...

    c1 = wHand[ 0 ];
    c2 = wHand[ 1 ];
    c3 = wHand[ 2 ];
    c4 = wHand[ 3 ];
    c5 = wHand[ 4 ];

    //printf( "c1 = %d\nc2 = %d\nc3 = %d\nc4 = %d\nc5 = %d\n" , c1 , c2 , c3 , c4 , c5 );
    if ( c1 == c2 || c1 == c3 || c1 == c4 || c1 == c5 || c2 == c3 || c2 == c4 || c2 == c5 || c3 == c4 || c3 == c5 || c4 == c5 ){
        return 1;
    }else{
        return 0;
    }
}

int isTwoPair( int wHand[ 5 ] )
{
    int counter = 0;
    int c1 , c2 , c3 , c4 , c5; //means column for card 1 , column for card 2 ...

    c1 = wHand[ 0 ];
    c2 = wHand[ 1 ];
    c3 = wHand[ 2 ];
    c4 = wHand[ 3 ];
    c5 = wHand[ 4 ];

    //printf( "c1 = %d\nc2 = %d\nc3 = %d\nc4 = %d\nc5 = %d\n" , c1 , c2 , c3 , c4 , c5 );
    if ( c1 == c2 || c1 == c3 || c1 == c4 || c1 == c5 ){
        ++counter;
    }
    if ( c2 == c3 || c2 == c4 || c2 == c5 ){
        ++counter;
    }
    if ( c3 == c4 || c3 == c5 ){
        ++counter;
    }
    if ( c4 == c5 ){
        ++counter;
    }

    //counter > 2 imply that hand contains 2 pairs
    if ( counter >= 2 ){
        return 1;
    }else{
        return 0;
    }
}

int isThreeOfaKind( int c[ 5 ] )
{
    int counter = 0;
    int k , i;

    for ( k = 0; k < 4; ++k ){
        for ( i = k + 1; i <= 4; ++i ){
            if ( c[ k ] == c[ i ] ){
                ++counter;
            }
        };
    }

    //counter > 2 imply that hand contains 2 pairs
    if ( counter >= 3 ){
        return 1;
    }else{
        return 0;
    }
}

int isFourOfaKind( int c[ 5 ] )
{
    int counter = 0;
    int k , i;

    for ( k = 0; k < 4; ++k ){
        for ( i = k + 1; i <= 4; ++i ){
            if ( c[ k ] == c[ i ] ){
                ++counter;
            }
        };
    }

    //counter == 6 imply that hand contains 4 of a kind ( compare to the right )
    if ( counter >= 6 ){
        return 1;
    }else{
        return 0;
    }
}

int isFlush( int wHand[ 5 ] )
{
    int c1 , c2 , c3 , c4 , c5;

    c1 = wHand[ 0 ];
    c2 = wHand[ 1 ];
    c3 = wHand[ 2 ];
    c4 = wHand[ 3 ];
    c5 = wHand[ 4 ];

    if ( c1 == c2 && c2 == c3 && c3 == c4 && c4 == c5 ){
        return 1;
    }else{
        return 0;
    }
}

int isStraight( const int wHand[ 5 ] )
{
    int c[ 5 ] = { 0 };
    int i;

    //copy values of wHand[] into c[]
    for ( i = 0; i < 5; ++i ){
        c[ i ] = wHand[ i ];
    }

    bubbleSort( c , 5 );

    for ( i = 0; i < 4; ++i ){
        //if next value is not equal to current value + 1,
        if ( c[ i + 1 ] != c[ i ] + 1 ){
            return 0;
        }
    }
    return 1;
}


int getColumn( int card , const int wDeck[][ 13 ] )
{
    int row , column;
    for ( row = 0; row <= 3; ++row ){
        for ( column = 0; column <= 12; ++column ){
            if ( wDeck[ row ][ column ] == card ){
                return column;
            }
        }
    }
    return -1;
}

void printHand( int wHand[][ 5 ] )
{
    int i , j;

    for ( i = 0; i < 2; ++i ){
        for ( j = 0; j < 5; ++j ){
            printf( "%3d" , wHand[ i ][ j ] );
        }printf( "\n" );
    }printf( "\n" );
}

void bubbleSort( int array[] , int size )
{
    int pass , hold;
    int j;

    for ( pass = 0; pass < size - 1; ++pass ){
        for ( j = 0; j < size - 1; ++j ){
            if ( array[ j ] > array[ j + 1 ] ){
                hold = array[ j ];
                array[ j ] = array[ j + 1 ];
                array[ j + 1 ] = hold;
            }
        }
    }

    //for debugging purpose
    /*printf( "after bubble sort, c[] = " );
    for ( j = 0; j < size; ++j ){
        printf( "%3d" , array[ j ] );
    }printf( "\n" );*/
}
